#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    printf("sigint_handler:%d\n", signum);
    exit(signum);
}

int main(int argc, char const *argv[])
{
    if (signal(SIGINT, sigint_handler) == SIG_ERR) {
        perror("signal");
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        sleep(1);
        printf("hello\n");
    }
    
    return 0;
}
