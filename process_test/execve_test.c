#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    char * name = "张三";
    printf("%s: %d, ppid: %d\n", name, getpid(), getppid());

    /**
     * const char *__path  程序路径
     * char *const __argv[] 传入的参数 最后一个参数一定是NULL
     * char *const __envp[] 传入的环境变量 最后一个参数一定是NULL
     * 
     * return: 成功根本没办法返回  下面的代码没有意义
     *          失败返回-1
     * 
     * 跳转前后只有进程号保留下来 别的变量都删除了
     */

    char * argv[] = {"test_ex", name, NULL};
    char * envp[] = {NULL};
    int ret = execve(argv[0], argv, envp);
    if (ret == -1)
    {
        perror("execve");
        exit(EXIT_FAILURE);
    }
    //execve执行成功，下面的代码就不会执行了，也没有意义
    return 0;
}
