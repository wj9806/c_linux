#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define THREAD_COUNT 20000
static int cnt = 0;

void * add(void * arg) {
    cnt++;
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
