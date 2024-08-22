#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    //打开文件
    int fd = open("io2.txt", O_RDONLY, 0664);   
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[32];
    int len;
    while ((len = read(fd, buf, sizeof(buf))) > 0)
    {
        write(STDOUT_FILENO, buf, len);
    }
    //关闭打开的文件描述符
    close(fd);
    return 0;
}
