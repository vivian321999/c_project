/* char-basics.c */
#include <stdio.h>
int main(void) {
    char c = 'A';
    printf("字符: %c, 码值: %d\n", c, c);
    // 字符就是小整数，可以直接参与运算
    printf("'a'=%d, '0'=%d, 'A'+1=%c\n", 'a', '0', 'A' + 1);
    // 转义字符与不同进制写法
    printf("\\n 换行, \\t 制表, \\\\ 反斜杠\n");
    printf("'\\101'=%c, '\\x41'=%c\n", '\101', '\x41');  // 都是 A
    // '\0'：ASCII 0，字符串的结束标志（重点）
    char term = '\0';
    printf("'\\0' 的码值 = %d\n", term);
    printf("sizeof(char)=%d, sizeof('A')=%d\n", (int)sizeof(char), (int)sizeof('A'));
    return 0;
}
