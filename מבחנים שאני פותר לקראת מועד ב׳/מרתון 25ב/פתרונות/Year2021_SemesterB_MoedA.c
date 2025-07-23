#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct item
{
    int data;
    struct item *next;
} Item;

Item *ex2(Item *L1, Item *L2)
{
    if (L1->next == L1)
    { // L1 have only one item
        mergeOneItemLists(L1, L2);
    }
    else if (L2->next == L2)
    { // L2 have only one item
        mergeOneItemLists(L2, L1);
    }
    Item* ptr1 = NULL,* ptr2 = NULL;
    findCommonItemInLists(L1, L2, &ptr1, &ptr2);
    Item* head = ptr1->next;
    ptr1->next = ptr2->next->next;
    free(ptr2->next);
    ptr2->next = head;
    return head;
}

Item *findCommonItemInOneItemList(Item *L1, Item *L2)
{ // L1 is the list with one item
    while (L2->data != L1->data)
    {
        L2 = L2->next;
    }
    free(L1);
    return L2;
}

void findCommonItemInLists(Item *L1, Item *L2, Item **ptr1, Item **ptr2)
{
    Item* prevL1 = L1, *prevL2 = NULL, *currL1 = L1->next, *currL2 = NULL;
    while (1) {
        prevL2 = L2;
        currL2 = L2->next;
        do {
            if (currL2->data != currL1->data) {
                prevL2 = currL2;
                currL2 = currL2->next;
            } else {
                *ptr1 = prevL1;
                *ptr2 = prevL2;
                return;
            }
        } while (currL2 != L2->next);
        prevL1 = currL1;
        currL1 = currL1->next;
    }
}