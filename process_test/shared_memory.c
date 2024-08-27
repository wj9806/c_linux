#include <sys/mman.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    //1.创建一个共享内存对象
    char shm_name[100] = {0};
    sprintf(shm_name, "/letter%d", getpid());

    int fd = shm_open(shm_name, O_RDWR | O_CREAT, 0644);
    if (fd < 0)
    {
        perror("shm_open");
        exit(EXIT_FAILURE);
    }
    
    //2 设置共享内存对象的大小
    ftruncate(fd, 1024);

    // 3. 进行内存映射
    char * share = mmap(NULL, 1024, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    if (share == MAP_FAILED)
    {
        perror("mmap");
        exit(EXIT_FAILURE);
    }
    close(fd);
    
    // 4 使用内存映射 实现进程间的通讯
    pid_t pid = fork();
    if (pid == 0)
    {
        strcpy(share, "hellommap\n");
    }
    else
    {
        waitpid(pid, NULL, 0);
        printf("内容：%s", share);

        //5. 释放映射区
        int ret = munmap(share, 1024);
        if(ret == -1) {
            perror("munmap");
            exit(EXIT_FAILURE);
        }
    }

    //6 释放共享内存对象
    shm_unlink(shm_name);
    return 0;
}
