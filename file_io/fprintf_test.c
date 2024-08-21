#include <stdio.h>

int main(int argc, char const *argv[])
{
    /**
     * const char *__restrict __filename, 文件名
	 * const char *__restrict __modes   访问模式 
     *  r 只读
     *  w 只写
     *  a 只追加写模式 
     *  r+: 读写模式  写入是从头一个一个覆盖
     *  w+: 读写模式  如果文件存在清空文件
     *  a+: 读写追加模式 如果文件存在末尾追加写
     * 
     * return: FILE* 
     */
    FILE * f = fopen("io.txt", "w");
    if (f == NULL) {
        printf("open file failed\n");
    } else {
        printf("open file success\n");
    }

    /**
     * FILE *__restrict __stream 文件
     * const char *__restrict __fmt 带格式化的长字符串
     * ...  可变参数
     * return 成功返回写入字符的个数,不包含换行符 失败返回EOF
     */
    int fprintf_res = fprintf(f, "1+1=%d", 2);
    if (fprintf_res == EOF) {
        printf("fprintf file failed\n");
    } else {
        printf("fprintf file success, write size=%d\n", fprintf_res);
    }
    
    
    /**
     * return 成功返回0 失败返回EOF(负数)
     */
    int res = fclose(f);
    if (res == EOF) {
        printf("close file failed\n");
    } else {
        printf("close file success\n");
    }
    
    return 0;
}
