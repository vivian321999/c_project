#include <stdio.h>

#define MAX_LEN 100

int main() {
    int count, arr[MAX_LEN];

    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    return 0;
}