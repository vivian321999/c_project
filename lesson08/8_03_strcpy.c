#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[32];
    const char* src = "I love China!";

    strcpy(dest, src); /* 连 '\0' 一起复制 */
    printf("strcpy : %s\n", dest);

    strcpy(dest, "You are a student.");
    printf("strcpy : %s\n", dest);

    memset(dest, 0, sizeof(dest)); /* 先清零，保证后面有 '\0' */
    strncpy(dest, src, 4);         /* 只复制前 4 个字符，不补 '\0' */
    printf("strncpy: %s\n", dest); /* I lo */

    /* 危险示范（别照抄）：目标太小会越界
       char small[5];
       strcpy(small, src);   // 未定义行为！
    */
    return 0;
}