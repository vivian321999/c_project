#include <stdio.h>
#include <stdlib.h>

#include "node.h"

// 练习3：给出下面两个函数的实现，包括描述、实现和测试
NODE_PTR ListReverse(NODE_PTR li);
NODE_PTR ListFind(NODE_PTR li, int i);
// 你也可以适当修改以上声明

void printList(NODE_PTR li) {
    for (NODE_PTR p = li; p; p = p->next) printf("%d,", p->customerData);
    printf("\n");
}

/**************
删除指定位置的元素

参数：
    li 指向要删除元素的指针的指针
    通常是子链表 e.next 或 链表头 p 的指针
返回值：
    删除元素后的子链表指针
**************/
NODE_PTR ListDelete(NODE_PTR* li) {
    *li = ListRemove(*li);
    return *li;
}

/***********
练习1：给出函数描述
***********/
NODE_PTR ListInsert(NODE_PTR* li, int i) {
    // 给出函数实现
    return *li;
}

int main(void) {
    int arr[10];
    for (int i = 0; i < 10; i++) arr[i] = i + 1;
    NODE_PTR list = ListCreate(arr, 10);
    printList(list);

    // place your code here, for example
    ListInsert(&list, 11);
    NODE_PTR p = ListIndex(list, 3);
    ListInsert(&p->next, 12);
    p = ListIndex(list, ListLength(list) - 1);
    ListInsert(&p->next, 13);
    // output is 11,1,2,3,12,4,5,6,7,8,9,10,,13,
    printList(list);

    p = ListIndex(list, ListLength(list) - 2);
    ListDelete(&p->next);
    // 练习2 给出测试案例
    // output is 1,2,3,4,5,6,7,8,9,10,
    printList(list);

    ListFree(list);
    return 0;
}
