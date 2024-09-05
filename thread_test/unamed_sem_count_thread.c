#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <semaphore.h>

sem_t * full;
sem_t * empty;

int num;

int rand_num() {
    srand(time(NULL));
    return rand();
}

void * producer_thread(void * arg) {
    for (int i = 0; i < 5; i++)
    {
        sem_wait(empty);
        printf("producer_thread:%d\n", i);
        sleep(1);
        num = rand_num();
        sem_post(full);
    }
    
}

void * consumer_thread(void * arg) {
    for (int i = 0; i < 5; i++)
    {
        sem_wait(full);
        printf("consumer_thread:%d\n", num);
        sleep(1);
        sem_post(empty);
    }
}

int main(int argc, char const *argv[])
{
    full = malloc(sizeof(sem_t));
    empty = malloc(sizeof(sem_t));

    sem_init(full, 0, 0);
    sem_init(empty, 0, 1);

    pthread_t producer, consumer;
    pthread_create(&producer, NULL, producer_thread, NULL);
    pthread_create(&consumer, NULL, consumer_thread, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    sem_destroy(full);
    sem_destroy(empty);
    free(full);
    free(empty);
    return 0;
}
