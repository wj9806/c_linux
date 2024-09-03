#include <pthread.h>
#include <bits/pthreadtypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//pthread_rwlock_t rwlock = __PTHREAD_RWLOCK_INITIALIZER;
pthread_rwlock_t rwlock;
int data = 0;

void * write_func() {
    pthread_rwlock_wrlock(&rwlock);
    int tmp = data + 1;
    sleep(1);
    data = tmp;
    pthread_rwlock_unlock(&rwlock);
}

void * read_func() {
    //获取读锁
    pthread_rwlock_rdlock(&rwlock);
    printf("%d\n", data);
    pthread_rwlock_unlock(&rwlock);
}

int main(int argc, char const *argv[])
{
    //显示初始化
    pthread_rwlock_init(&rwlock, NULL);

    pthread_t write1, write2, read1,read2;
    pthread_create(&write1, NULL, write_func, NULL);
    pthread_create(&write2, NULL, write_func, NULL);
    sleep(3);
    pthread_create(&read1, NULL, read_func, NULL);
    pthread_create(&read2, NULL, read_func, NULL);

    pthread_join(write1, NULL);
    pthread_join(write2, NULL);
    pthread_join(read1, NULL);
    pthread_join(read2, NULL);

    read_func();
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
