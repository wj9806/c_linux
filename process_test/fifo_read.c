#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char * pipe_path = "/tmp/myfifo";
    int fd = open(pipe_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[100];
    ssize_t read_num;
    //读取控制太数据写入到管道中
    while ((read_num = read(fd, buf, 100)) > 0)
    {
        write(STDOUT_FILENO, buf, read_num);
    }
    printf("接收数据成功\n");
    close(fd);
    return 0;
}
