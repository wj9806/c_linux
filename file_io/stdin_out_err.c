#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    char buf[30];
    fgets(buf, sizeof(buf), stdin);
    fputs(buf, stdout);
    return 0;
}