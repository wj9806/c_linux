#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void * task(void * arg) {
    while (1)
    {
        sleep(1);
        printf("task\n");
    }
}

int main(int argc, char const *argv[])
{
    // 创建线程
    pthread_t tid;
    pthread_create(&tid, NULL, task, NULL);
    //使用detach标记会等待线程完成之后回收相关资源
    pthread_detach(tid);

    //主线程不会在pthread_detach后等待，父线程结束后，会强制杀死子线程
    sleep(5);
    return 0;
}
