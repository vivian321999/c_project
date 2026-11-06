#include "stdio.h"
#define PI 3.1415926
void function(void);

int main(void) {
    printf("%f\n", PI);
    function();
}
#undef PI
#define PI 3.14
void function(void) { printf("%f\n", PI); }
