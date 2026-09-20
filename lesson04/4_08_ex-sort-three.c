/*ex-sort-three*/
#include <stdio.h>

int main() {
    int i, j, k;
    int max, min, median;

    printf("please three int number:");
    scanf("%d %d %d", &i, &j, &k);

    max = i > j ? (i > k ? i : k) : (j > k ? j : k);
    min = i < j ? (i < k ? i : k) : (j < k ? j : k);
    median = i + j + k - max - min;

    printf("%d %d %d\n", max, median, min);
}