#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_LEN 1024

char * buf;

void * input_thread(void * argv) {
    int i = 0;
    while (1)
    {
        char c = fgetc(stdin);
        if (c && c != '\n') {
            buf[i++] = c;
        }
        if(i >= BUF_LEN) {
            i = 0;
        }
    }
}


void * output_thread(void * argv) {
    int i = 0;
    while (1)
    {
        if(buf[i]) {
            fputc(buf[i], stdout);
            fputc('\n', stdout);
            buf[i++] = 0;
            if(i >= BUF_LEN) {
                i = 0;
            }
        } else {
            sleep(1);
        }
    }
}

int main(int argc, char const *argv[])
{
    buf = malloc(BUF_LEN * sizeof(char));
    pthread_t pid_input;
    pthread_t pid_output;
    pthread_create(&pid_input, NULL, input_thread, NULL);
    pthread_create(&pid_output, NULL, output_thread, NULL);

    //主线程等待读写线程执行结束
    pthread_join(pid_input, NULL);
    pthread_join(pid_output, NULL);

    free(buf);
    return 0;
}
