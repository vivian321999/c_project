#include <ctype.h>
#include <stdio.h>

int main(void) {
    char s[] = "Hello World 2026!";

    for (int i = 0; s[i] != '\0'; i++) s[i] = (char)tolower((unsigned char)s[i]);
    printf("lower: %s\n", s);

    for (int i = 0; s[i] != '\0'; i++) s[i] = (char)toupper((unsigned char)s[i]);
    printf("upper: %s\n", s);
    return 0;
}