/*while count string*/
#include <stdio.h>

int main(void) {
    int n = 0;

    printf("Input a string:");
    while (getchar() != '\n') n++;

    printf("Number of characters: %d\n", n);
    return 0;
}
