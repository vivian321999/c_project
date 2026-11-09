/* file-errno */
#include <errno.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    FILE* fp = fopen("no-such-file.txt", "r");
    if (fp == NULL) {
        int err = errno;  // 先保存，后面再翻译
        fprintf(stderr, "打开失败: errno=%d, %s\n", err, strerror(err));
        perror("fopen");  // 标准格式：fopen: ...
        return 1;
    }
    fclose(fp);
    return 0;
}
