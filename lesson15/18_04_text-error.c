#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE* fp = fopen("test.txt", "r");
    if (!fp) {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c;                            // 注意：int，非char，要求处理EOF
    while ((c = fgetc(fp)) != EOF) {  // 标准C I/O读取文件循环
        putchar(c);
    }

    if (ferror(fp))
        puts("I/O error when reading");
    else if (feof(fp))
        puts("End of file reached successfully");

    fclose(fp);
}
