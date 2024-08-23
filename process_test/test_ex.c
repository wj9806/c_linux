#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("test_ex:参数数目少了\n");
        return 1;
    }
    printf("test_ex参数: %s, pid: %d, ppid: %d\n", argv[1], getpid(), getppid());
    return 0;
}
