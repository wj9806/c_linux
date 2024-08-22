#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    /**
     * 使用标准库函数创建子进程
     * return 成功返回0 失败返回失败编号
     */
    int r  = system("ping -c 5 127.0.0.1");
    if (r != 0)
    {
        perror("system");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}
