#include <sys/mman.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <semaphore.h>

int value = 0;

/**
 * 
 * 进程间使用信号量通讯时，信号量必须置于共享内存区域
 */
int main(int argc, char const *argv[])
{

    //1.创建一个共享内存对象
    char * shm_name = "/letter";
    char * shm_sem_name = "unamed_sem_shm_sem";

    int fd = shm_open(shm_name, O_RDWR | O_CREAT, 0644);
    int sem_fd = shm_open(shm_sem_name, O_CREAT | O_RDWR, 0666);
    
    //2 设置共享内存对象的大小
    ftruncate(fd, sizeof(int));
    ftruncate(sem_fd, sizeof(sem_t));

    // 3. 进行内存映射
    int * value = mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sem_t * unamed_sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, sem_fd, 0);

    //初始化信号量
    sem_init(unamed_sem, 1, 1);

    *value = 0;
    
    // 4 使用内存映射 实现进程间的通讯
    pid_t pid = fork();
    if (pid == 0)
    {
        sem_wait(unamed_sem);
        int tmp = *value+1;
        sleep(1);
        *value = tmp;
        printf("value:%d\n", *value);
        sem_post(unamed_sem);
    }
    else
    {
        sem_wait(unamed_sem);
        int tmp = *value+1;
        sleep(1);
        *value = tmp;
        printf("value:%d\n", *value);
        sem_post(unamed_sem);
        waitpid(pid, NULL, 0);

        //5. 释放映射区
        if(sem_destroy(unamed_sem) != 0) {
            perror("sem destroy");
        }
    }

    int ret = munmap(value, sizeof(int));
    if(ret == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    close(fd);
    close(sem_fd);

    if (pid > 0) 
    {
        //6 释放共享内存对象
        shm_unlink(shm_name);
        shm_unlink(shm_sem_name);
    }
    return 0;
}
