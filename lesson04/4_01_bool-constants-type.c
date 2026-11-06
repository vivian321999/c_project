/*boolean constant and type*/
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    bool x = 7;  // 相当于 x=(_Bool)7
    bool b = false;
    printf("%x\n", x);
    printf("%zu %zu\n", sizeof(true), sizeof(b));
    printf("%zu %zu\n", sizeof(bool), sizeof(_Bool));
}