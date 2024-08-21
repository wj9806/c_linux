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
     * FILE *__restrict __stream 文件
     * const char *__restrict __format, 带格式化的字符串
     * ... 可变参数
     * return 成功匹配到的参数的个数 匹配失败返回0  报错或者到达文件末尾返回EOF
     */
    char buf[20]; int num;
    int r;
    while ((r = fscanf(f, "%s %d", buf, &num)) != EOF)
    {
        printf("%s %d\n", buf, num);
    }
    
    int res = fclose(f);
    if (res == EOF) {
        printf("close file failed\n");
    } else {
        printf("close file success\n");
    }
    
    return 0;
}
