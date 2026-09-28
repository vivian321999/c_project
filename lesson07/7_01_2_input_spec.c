#include <stdio.h>

#define MAX_LEN 100

int main() {
    int arr[MAX_LEN];

    int count = 0;
    const int SPEC = -1;
    do {
        scanf("%d", &arr[count++]);
    } while (arr[count - 1] != SPEC);
    count--;  //?

    for (int i = 0; i < count; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}