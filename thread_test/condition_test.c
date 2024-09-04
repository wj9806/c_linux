#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 5
int buffer[BUFFER_SIZE];
int count = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void * producer_thread(void * arg) {
    int item = 1;
    while (1)
    {
        pthread_mutex_lock(&mutex);

        //写满就等待
        if (count == BUFFER_SIZE)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        buffer[count++] = item++;
        printf("producer_thread\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
    
}

void * consumer_thread(void * arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        //写满就等待
        if (count == 0)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        printf("%d\n", buffer[--count]);
        printf("consumer_thread\n");
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mutex);
    }
}

int main(int argc, char const *argv[])
{
    pthread_t producer, consumer;
    pthread_create(&producer, NULL, producer_thread, NULL);
    pthread_create(&consumer, NULL, consumer_thread, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);
    return 0;
}
