#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() {
    int arr[MAX_LEN];

    int count = 0;
    while (scanf("%d", &arr[count++]) != EOF);
    count--;

    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}