#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
    char * pipe_path = "/tmp/myfifo";
    //创建有名管道
    if(mkfifo(pipe_path, 0664) != 0) {
        perror("mkfifo");
        if (errno != 17)
        {
            exit(EXIT_FAILURE);
        }

    }
    int fd = open(pipe_path, O_RDWR);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[100];
    ssize_t read_num;
    //读取控制太数据写入到管道中
    while ((read_num = read(STDIN_FILENO, buf, 100)) > 0)
    {
        write(fd, buf, read_num);
    }
    printf("发送数据成功\n");

    close(fd);
    //释放管道
    if(unlink(pipe_path) == -1) {
        perror("unlink");
    }
    return 0;
}
