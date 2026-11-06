#pragma once
#include <assert.h>
#include <stdlib.h>

typedef struct NODE Node;
typedef Node* NODE_PTR;

struct NODE {
    int customerData;
    NODE_PTR next;
};

NODE_PTR ListAdd(NODE_PTR li, int i);
NODE_PTR ListRemove(NODE_PTR li);

NODE_PTR ListCreate(int* arr, size_t n);
NODE_PTR ListFree(NODE_PTR li);

size_t ListLength(NODE_PTR li);
NODE_PTR ListIndex(NODE_PTR li, size_t Idx);

//--Implementations
NODE_PTR ListAdd(NODE_PTR li, int i) {
    NODE_PTR np = malloc(sizeof(Node));
    np->customerData = i;
    np->next = li;
    return np;
}

NODE_PTR ListRemove(NODE_PTR li) {
    if (li) {
        NODE_PTR p = li->next;
        free(li);
        return p;
    }
    return NULL;
}

NODE_PTR ListCreate(int* arr, size_t n) {
    NODE_PTR np = NULL;
    for (int i = n - 1; i > -1; i--) np = ListAdd(np, arr[i]);
    return np;
}

NODE_PTR ListFree(NODE_PTR li) {
    while (li) li = ListRemove(li);
    return li;
}

size_t ListLength(NODE_PTR li) {
    if (li)
        return ListLength(li->next) + 1;
    else
        return 0;
}

NODE_PTR ListIndex(NODE_PTR li, size_t Idx) {
    if (li && Idx)
        return ListIndex(li->next, --Idx);
    else
        return li;
}
