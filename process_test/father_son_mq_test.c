#include <sys/stat.h>
#include <mqueue.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    char * mq_name = "/my_mq";
    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = 100;
    attr.mq_curmsgs = 0;
    mqd_t mq = mq_open(mq_name, O_RDWR | O_CREAT, 0664, &attr);
    if (mq == -1)
    {
        perror("mq_open");
        exit(EXIT_FAILURE);
    }
    pid_t pid = fork();
    if (pid == 0)
    {
        char read_buf[100];
        struct timespec time;
        for (size_t i = 0; i < 10; i++)
        {
            memset(read_buf, 0, 100);
            clock_gettime(0, &time);
            time.tv_sec += 15;
            //接收消息队列消息
            if(mq_timedreceive(mq, read_buf, 100, NULL, &time) == -1) {
                perror("mq_timedreceive");
            }
            printf("子进程接受数据: %s", read_buf);
        }
    } 
    else
    {
        char send_buf[100];
        struct timespec time;
        for (int i = 0; i < 10; i++)
        {
            memset(send_buf, 0, 100);
            sprintf(send_buf, "父进程send%d\n", i + 1);
            clock_gettime(0, &time);
            time.tv_sec += 5;
            //发送消息到消息队列
            if(mq_timedsend(mq, send_buf, strlen(send_buf), 0, &time) == -1)
            {
                perror("mq_timedsend");
            }
            sleep(1);
        }
    }
    
    close(mq);
    //清除消息队列(只需要执行一次)
    if (pid > 0)
    {
        mq_unlink(mq_name);
    }
    return 0;
}
