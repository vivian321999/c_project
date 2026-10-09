#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[] = "Hell";
    char s2[] = "Hello";

    printf("strcmp(\"Hell\", \"Hello\") = %d\n", strcmp(s1, s2)); /* <0 */

    strcpy(s1, "ABcD");
    strcpy(s2, "ABCD");
    printf("strcmp(\"ABcD\", \"ABCD\") = %d\n", strcmp(s1, s2)); /* >0，'c' > 'C' */

    printf("strcmp(\"I am fine\", \"I am fine\") = %d\n", strcmp("I am fine", "I am fine")); /* 0 */

    printf("strncmp(\"ABCD\", \"ABCd\", 3) = %d\n", strncmp("ABCD", "ABCd", 3)); /* 0 */

    /* 常见错误：
       if (s1 == s2) ...   // 比较的是两个数组的地址，不是内容！
    */
    return 0;
}