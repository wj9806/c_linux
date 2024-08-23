#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{
    printf("父进程执行: %d\n", getpid());
    //使用fork创建子进程
    
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        printf("子进程：%d, 父进程: %d\n", getpid(), getppid());
    } else {
        printf("当前进程: %d\n", getpid());
    }
    
    
    return 0;
}
