#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, char const *argv[])
{

    int fd = open("io.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char buf[1024];
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
    } else if (pid == 0) {
        strcpy(buf, "子进程数据\n");
    } else {
        sleep(1);
        strcpy(buf, "父进程数据!\n");
    }

    ssize_t bytes = write(fd, buf, strlen(buf));
    printf("写出字节: %ld\n", bytes);
    close(fd);
    return 0;
}
