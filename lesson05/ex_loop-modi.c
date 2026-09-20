/*loop*/
#include <stdio.h>

int main() {
    int sum = 0;
    int i = 1;
    while (sum <= 100) {
        sum += i;
        i++;
    }
    printf("The i and sum is %d %d\n", i - 2, sum - i + 1);
}