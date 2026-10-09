#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "Hello!"; /* 7 个字节：6 个字符 + '\0' */
    const char* msg = "C PROGRAMMING!";

    printf("strlen(str) = %u\n", (unsigned)strlen(str)); /* 6  */
    printf("sizeof(str) = %u\n", (unsigned)sizeof(str)); /* 7  */
    printf("strlen(msg) = %u\n", (unsigned)strlen(msg)); /* 14 */

    /* 不调用库函数，自己数一遍，验证 strlen 的含义 */
    unsigned int n = 0;
    while (str[n] != '\0') n++;
    printf("my_strlen(str) = %u\n", n); /* 6  */
    return 0;
}