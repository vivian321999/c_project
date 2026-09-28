#include <stdio.h>

#define MAX_LEN 100

int main() {
    int arr[MAX_LEN];

    int count = 0;
    do {
        scanf("%d", &arr[count++]);
    } while (arr[count - 1] != -1);

    count--;  //?
    // Remove the -1 from the array
    for (int i = 0; i < count; i++) {
        printf("%d\n", arr[i]);
    }
    printf("\n");
    return 0;
}