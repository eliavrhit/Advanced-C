#include <stdio.h>
#include <stdlib.h>

/*ex1*/

typedef struct node {
    char value;
    struct node* next;
} node;

void removeExtraSpaces(node** head);
node* createNode(char value);
void printList(node* head);
void freeList(node* head);

node* createNode(char value) {
    node* newNode = (node*)malloc(sizeof(node));
    if (newNode) {
        newNode->value = value;
        newNode->next = NULL;
    }
    return newNode;
}

void printList(node* head) {
    while (head) {
        printf("'%c' -> ", head->value);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(node* head) {
    node* temp;
    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    // צור את הרשימה: "  No   way !  "
    char values[] = {' ', ' ', 'N', 'o', ' ', ' ', ' ', 'w', 'a', 'y', ' ', '!', ' ', ' '};
    int n = sizeof(values) / sizeof(values[0]);

    node* head = NULL;
    node* tail = NULL;

    for (int i = 0; i < n; i++) {
        node* newNode = createNode(values[i]);
        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }
        tail = newNode;
    }

    printf("Before:\n");
    printList(head);

    removeExtraSpaces(&head);  // קריאה לפונקציה שאתה אמור לממש

    printf("After:\n");
    printList(head);

    freeList(head);
    return 0;
}

void removeExtraSpaces(node** head) {

    if (*head == NULL) return;

    node* current = (*head)->next;
    while (current && current->value == ' ') {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    (*head)->next = current;

    current = (*head)->next;
    node* prev = NULL;

    while (current && current->next) {
        if (current->value == ' ' && current->next->value == ' ') {
            node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }

    if ((*head)->next == NULL) return;

    node* lastNonSpace = NULL;
    current = (*head)->next;
    while (current) {
        if (current->value != ' ') {
            lastNonSpace = current;
        }
        current = current->next;
    }

    if (lastNonSpace && lastNonSpace->next) {
        // מחק הכל אחרי האחרון שאינו רווח
        current = lastNonSpace->next;
        lastNonSpace->next = NULL;
        while (current) {
            node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
