#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[16];
    printf("请输入一行文本（最多 15 个字符）: ");

    if (fgets(buf, sizeof(buf), stdin) == NULL) { /* 安全读入一行 */
        printf("输入失败\n");
        return 1;
    }

    char* p = strchr(buf, '\n'); /* fgets 会把 '\n' 也读进来 */
    if (p != NULL) *p = '\0';    /* 有换行就替换成字符串结束符 */

    printf("[%s] len=%u\n", buf, (unsigned)strlen(buf));
    return 0;
}