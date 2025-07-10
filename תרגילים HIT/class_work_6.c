//אליאב המלך

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char sign;
    struct node* next;
} Node;

Node* insertSorted(Node* head, char ch);
void printList(Node* head);
void reverse(Node** head);
void freeList(Node* head);

void main () {

    // Initialize head of the list to NULL (empty list)
    Node* head = NULL;
    // Initialize character variable to null character
    char ch = '\0';
    // Loop until character '0' is entered
    while (ch != '0') {
        // Prompt user to enter a character
        printf("Please enter a character : ");
        // Read a character from user input (skip whitespace)
        scanf(" %c", &ch);
        // If character is '0', break the loop and stop input
        if (ch == '0') {
            break;
        }
        // Insert the character into the sorted linked list
        head = insertSorted(head, ch);
    }
    // Print the linked list in sorted order
    printList(head);
    printf("\n");
    // Print message before printing reversed list
    printf("reversed list: \n");
    // Reverse the linked list (modifies the list)
    reverse(&head);
    // Print the reversed linked list
    printList(head);
    // Free all allocated nodes in the list
    freeList(head);

}

Node* insertSorted(Node* head, char ch) {

    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // If list is empty, insert new node as head
    if (head == NULL) {
        // Assign character to new node
        newNode->sign = ch;
        // Set next pointer of new node to NULL (end of list)
        newNode->next = NULL;
        // Return new node as head
        return newNode;
    }
    else {
        // If character is less than head's sign, insert at beginning
        if (ch < head->sign) {
            // Assign character to new node
            newNode->sign = ch;
            // Point new node's next to current head
            newNode->next = head;
            // Return new node as new head
            return newNode;
        }
        else {
            // Traverse list to find insertion point
            Node* curr = head;
            // Move forward until next node is NULL or next node's sign is not less than ch
            while (curr->next != NULL && curr->next->sign < ch) {
                curr = curr->next;
            }
            // Assign character to new node
            newNode->sign = ch;
            // Insert new node after current node
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }
    // Return head of the list
    return head;
}

void printList(Node* head) {

    // Initialize current pointer to head
    Node* curr = head;
    // Traverse the list until end
    while (curr != NULL) {
        // Print the character of current node
        printf("%c", curr->sign);
        // Move to next node
        curr = curr->next;
    }
}

void reverse(Node** head) {

    // Initialize current pointer to head, previous pointer to NULL, and next pointer
    Node* curr = *head, *prev = NULL, *next;
    // Iterate through the list until current is NULL
    while (curr != NULL) {
        // Store the next node before changing current's next
        next = curr->next;
        // Reverse the current node's pointer to point to previous node
        curr->next = prev;
        // Move prev to current node
        prev = curr;
        // Move to next node in original list
        curr = next;
    }
    // Update head to the new first node (prev)
    *head = prev;

}

void freeList(Node* head) {
    // Start from the head of the list
    Node* curr = head;
    // Traverse and free each node
    while (curr != NULL) {
        // Save the next node pointer before freeing current
        Node* next = curr->next;
        // Free the current node
        free(curr);
        // Move to the next node
        curr = next;
    }
}