#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * task(void * arg) {
    printf("task start\n");
    sleep(1);

    //调用取消点函数
    pthread_testcancel();

    printf("after cancel\n");
    return NULL;
}

int main(int argc, char const *argv[])
{
    // 创建线程
    pthread_t tid;
    pthread_create(&tid, NULL, task, NULL);
    //取消子线程
    if (pthread_cancel(tid) != 0)
    {
        perror("cancel");
        exit(EXIT_FAILURE);
    }
    void * res;
    pthread_join(tid, &res);

    if (res == PTHREAD_CANCELED)
    {
        printf("线程被取消\n");
    } else {
        printf("线程没有取消, exit code %ld\n", (long)res);
    }
    
    return 0;
}
