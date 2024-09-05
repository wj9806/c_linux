#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
#include <sys/types.h>
#include <fcntl.h>

#define THREAD_COUNT 20000
static int cnt = 0;
sem_t * named_sem;

void * add(void * arg) {
    //信号量互斥
    sem_wait(named_sem);
    cnt++;
    //信号量加一
    sem_post(named_sem);
}

int main(int argc, char const *argv[])
{
    char * name = "/mysem";
    named_sem = sem_open(name, O_CREAT, 0666, 1);
    if (named_sem == SEM_FAILED)
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

    if(sem_close(named_sem) == -1) {
        perror("sem_close");
    }
    return 0;
}