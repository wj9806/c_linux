#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE * f = fopen("io.txt", "r");
    if (f == NULL) {
        printf("open file failed\n");
    } else {
        printf("open file success\n");
    }

    /**
     * char *__restrict __s, 接受读取到的字符串
     * int __n, 接受数据的长度
     * FILE *__restrict __stream 打开要读取的文件
     * return 返回字符串，失败返回NULL
     */
    char buf[100];
    while (fgets(buf, sizeof(buf), f))
    {
        printf("%s", buf);
    }
    
    
    int res = fclose(f);
    if (res == EOF) {
        printf("close file failed\n");
    } else {
        printf("close file success\n");
    }
    
    return 0;
}
