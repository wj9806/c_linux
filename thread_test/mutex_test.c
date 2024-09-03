#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_COUNT 20000
static int cnt = 0;

//静态初始化的锁会在程序执行完成后会自动销毁
//通过pthread_mutex_init初始化的锁需要显式销毁
static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void * add(void * arg) {
    pthread_mutex_lock(&mutex);
    cnt++;
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t pid[THREAD_COUNT];
    for (size_t i = 0; i < THREAD_COUNT; i++)
    {
        pthread_create(&pid[i], NULL, add, NULL);
    }
    
    for (size_t i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(pid[i], NULL);
    }

    printf("cnt: %d\n", cnt);
    return 0;
}
