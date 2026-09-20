/*boolean constant and type*/
#include <stdbool.h>
#include <stdio.h>

int main() {
    bool x = 7;  // 相当于 x=(_Bool)7
    bool b = false;
    printf("%x\n", x);
    printf("%u %u\n", sizeof(true), sizeof(b));
    printf("%u %u\n", sizeof(bool), sizeof(_Bool));
}