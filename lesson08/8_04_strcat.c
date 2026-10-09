#include <stdio.h>
#include <string.h>

int main(void) {
    char dest[32] = "I love "; /* 必须是可写数组，且足够长 */
    const char* src = "China!";

    strcat(dest, src);             /* 去掉 dest 的 '\0'，把 src 接到末尾 */
    printf("strcat : %s\n", dest); /* I love China! */

    strcpy(dest, "I love ");
    strncat(dest, src, 2);         /* 最多接 2 个字符，并自动补 '\0' */
    printf("strncat: %s\n", dest); /* I love Ch */

    /* 危险示范（别照抄）：
       char small[8] = "I love ";
       strcat(small, "China!");   // 越界写！
    */
    return 0;
}