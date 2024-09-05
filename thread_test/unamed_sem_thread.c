#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define THREAD_COUNT 20000
sem_t unamed_sem;
static int cnt = 0;

void * add(void * arg) {
    //信号量互斥
    sem_wait(&unamed_sem);
    cnt++;
    //信号量加一
    sem_post(&unamed_sem);
}

int main(int argc, char const *argv[])
{
    /** pshared 0线程间使用 1进程间通讯 */
    if (sem_init(&unamed_sem, 0, 1) != 0)
    {
        perror("sem");
        exit(EXIT_FAILURE);
    }

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

    if(sem_destroy(&unamed_sem) != 0) {
        perror("sem destroy");
    }
    return 0;
}