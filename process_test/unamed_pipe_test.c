#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * pipefd[0] 指向管道的读端
 * pipefd[1] 指向管道的写端
 * 
 * int pipe (int pipefd[2])
 * return 0 成功 -1 失败
 */
int main(int argc, char const *argv[])
{
    //将程序传递进来的第一个命令行参数 通过管道传输给子进程
    if (argc != 2)
    {
        fprintf(stderr, "参数不够\n");
        exit(EXIT_FAILURE);
    }

    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        perror("创建管道失败");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    if (pid == 0) {
        //子进程读取管道数据 打印到控制台
        close(pipefd[1]);
        char buf;
        while (read(pipefd[0], &buf, 1) > 0)
        {
            write(STDOUT_FILENO, &buf, 1);
        }
        buf = '\n';
        write(STDOUT_FILENO, &buf, 1);
        close(pipefd[0]);
        _exit(EXIT_FAILURE);
    } else{
        //写入管道数据 提供给子进程读
        close(pipefd[0]);
        write(pipefd[1], argv[1], strlen(argv[1]));
        close(pipefd[1]);
        waitpid(pid, NULL, 0);
    }
    
    return 0;
}
