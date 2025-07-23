#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct item {
    int data;
    struct item* next;
    struct item* prev;
} Item;

int ex1(Item* head, Item* tail) {
    int result = 1, diff;
    while (head != tail) { // for odd list
        diff = abs(head->data - tail->data);
        if (diff > 1) {
            return 0;
        }
        if (diff == 1) {
            result = 2;
        }
        head = head->next;
        // for even list
        if (head == tail) {
            break;
        }
        tail = tail->prev;
    }
    return result;
}