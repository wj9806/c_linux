#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    char * shm_name = "unamed_sem_shm";
    //创建共享内存
    int fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    //调整共享内存大小
    ftruncate(fd, sizeof(sem_t));
    //完成映射
    sem_t * sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sem_init(sem, 1, 0);

    pid_t pid = fork();
    if (pid < 0)
    {
        perror("fork");
    } else if (pid == 0) {
        sleep(1);
        printf("子进程\n");
        sem_post(sem);
    } else {
        sem_wait(sem);
        printf("父进程\n");
        waitpid(pid, NULL, 0);
    }
    if (pid > 0)
    {
        sem_destroy(sem);
    }

    //父子进程都需要关闭文件描述符
    munmap(sem, sizeof(sem));
    if (pid > 0)
    {
        shm_unlink(shm_name);
    }
    
    return 0;
}
