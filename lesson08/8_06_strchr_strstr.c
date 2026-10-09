#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "abcdedcbaf";
    char* p; /* 指针变量：下周展开讲 */

    p = strchr(str, 'd'); /* 返回第一次出现 'd' 的位置 */
    if (p != NULL)
        printf("strchr: %s\n", p); /* dedcbaf */
    else
        printf("strchr: not found\n");

    if (strchr(str, 'z') == NULL) /* 找不到返回 NULL */
        printf("strchr: 'z' not exist\n");

    p = strstr(str, "ded"); /* 返回第一次出现子串的位置 */
    if (p != NULL)
        printf("strstr: %s\n", p); /* dedcbaf */
    else
        printf("strstr: not found\n");

    return 0;
}