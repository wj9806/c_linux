#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static int num = 0;

int main(int argc, char const *argv[])
{
   pid_t pid = fork(); 
   if (pid == 0) {
        num = 1;
        printf("子进程: %d\n", num);
   } else {
        sleep(1);
        printf("父进程: %d\n", num);
   }
    return 0;
}
