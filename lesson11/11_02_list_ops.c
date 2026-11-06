#include <stdio.h>
#include <stdlib.h>

#include "node.h"

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; i++) arr[i] = i + 1;
    NODE_PTR list = ListCreate(arr, 10);

    for (NODE_PTR p = list; p; p = p->next) printf("%d,", p->customerData);
    printf("\n");

    printf("len = %zu\n", ListLength(list));
    printf("li[3] = %d\n", ListIndex(list, 3)->customerData);

    list = ListAdd(list, 11);
    printf("add = %d\n", list->customerData);
    list = ListRemove(list);
    printf("removed = %d\n", list->customerData);

    for (NODE_PTR p = list; p; p = p->next) printf("%d,", p->customerData);
    printf("\n");

    ListFree(list);
    return 0;
}
