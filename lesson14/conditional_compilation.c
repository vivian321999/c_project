#include <stdio.h>
#define DEBUG 1
int main(void) {
    char str[20] = "C Language", c;
    int i;
    i = 0;
    while ((c = str[i]) != '\0') {
        i++;
#if DEBUG
        if (c >= 'a' && c <= 'z') c = c - 32;
#else
        if (c >= 'A' && c <= 'Z') c = c + 32;
#endif
        printf("%c", c);
    }
}
