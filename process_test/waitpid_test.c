#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
    int sub_status;
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        char * args[] = {"/usr/bin/ping", "-c", "10", "127.0.0.1", NULL};
        char * envs[] = {NULL};
        execve(args[0], args, envs);
    } else {
        printf("当前进程: %d\n", getpid());
        waitpid(pid, &sub_status, 0);
    }
    printf("等待完成, sub_status=%d\n", sub_status);
    return 0;
}
