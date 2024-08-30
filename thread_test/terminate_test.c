#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <string.h>

typedef struct Result
{
    char * p;
    int len;
} Result;

void * red_thread(void* arg) {
    Result * result = malloc(sizeof(Result));
    char code = *(char*) arg;
    char * ans = malloc(100);
    while (1)
    {
        fgets(ans, 99, stdin);
        if (ans[0] == code)
        {
            free(ans);
            printf("free ans");

            char * redans = strdup("strdup");
            result->p = redans;
            result->len = strlen(redans);
            pthread_exit(result);
        } else {
            printf("red wait\n");
        }
        
    }
    
    
}

void * white_thread(void* arg) {
    Result * result = malloc(sizeof(Result));
    char code = *(char*) arg;
    char * ans = malloc(100);
    while (1)
    {
        fgets(ans, 99, stdin);
        if (ans[0] == code)
        {
            free(ans);
            printf("free ans2\n");

            char * redans = strdup("strdup2");
            result->p = redans;
            result->len = strlen(redans);
            pthread_exit(result);
        } else {
            printf("red wait2\n");
        }
        
    }
}

int main(int argc, char const *argv[])
{
    Result * red_result;
    Result * white_result;
    char red = 'r';
    char white = 'w';
    pthread_t pid_red;
    pthread_t pid_white;
    pthread_create(&pid_red, NULL, red_thread, &red);
    pthread_create(&pid_white, NULL, white_thread, &white);

    pthread_join(pid_red, (void**)&red_result);
    pthread_join(pid_white, (void**)&white_result);

    printf("red:%s", red_result->p);
    printf("white:%s", white_result->p);

    free(red_result->p);
    free(red_result);

    free(white_result->p);
    free(white_result);
    return 0;
}
