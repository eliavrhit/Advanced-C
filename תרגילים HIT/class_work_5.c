#include <stdio.h>
#include <stdlib.h>

/**/
// Definition of a node in the linked list
typedef struct node
{
    int data;
    struct node* next;
} Node;

// Function to create a new node with a given value
Node* insertSorted (int value);
// Reads integers and separates them into even and odd linked lists
int insertNumbers(Node** evenHead, Node** oddHead);
// Prints the elements of a linked list
void printList(Node* head);
// Frees all memory allocated for the linked list
void freeList(Node* head);

int processList(Node* head, int* min, int* max);

int main() {
    // Declare pointers for even and odd linked lists
    Node *evenList, *oddList;
    int totalNumbers;

    // Read numbers and build both lists
    totalNumbers = insertNumbers(&evenList, &oddList);

    // Print even list
    printf("\nרשימת מספרים זוגיים:\n");
    printList(evenList);

    // Process even list
    int evenSum, evenMin, evenMax;
    evenSum = processList(evenList, &evenMin, &evenMax);
    printf("סיכום זוגיים: סכום = %d, מינימום = %d, מקסימום = %d\n", evenSum, evenMin, evenMax);

    // Print odd list
    printf("\nרשימת מספרים אי-זוגיים:\n");
    printList(oddList);

    // Process odd list
    int oddSum, oddMin, oddMax;
    oddSum = processList(oddList, &oddMin, &oddMax);
    printf("סיכום אי-זוגיים: סכום = %d, מינימום = %d, מקסימום = %d\n", oddSum, oddMin, oddMax);

    // Print total count
    printf("\nסך כל המספרים שנקלטו: %d\n", totalNumbers);

    // Free allocated memory for both lists
    freeList(evenList);
    freeList(oddList);

    return 0;
}

int processList(Node* head, int* min, int* max) {
    if (head == NULL) {
        printf("הרשימה ריקה.\n");
        *min = *max = 0;
        return 0;
    }
    int sum = 0;
    *min = *max = head->data;
    while (head != NULL) {
        sum += head->data;
        if (head->data < *min) *min = head->data;
        if (head->data > *max) *max = head->data;
        head = head->next;
    }

    return sum;

}

Node* insertSorted (int value) {
    // Allocate memory for new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    // Check for memory allocation failure
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // סיום מיידי אם אין זיכרון
    }
    // Initialize node data
    newNode->data = value;
    // Initialize node pointer
    newNode->next = NULL;
    return newNode;
}

// Function to read numbers and categorize them
int insertNumbers(Node** evenHead, Node** oddHead) {

    int num, count = 0;
    *evenHead = NULL;
    *oddHead = NULL;
    Node *evenTail = NULL, *oddTail = NULL;

    printf("הכנס מספרים שלמים (-1 לסיום):\n");

    // Continuously read input until -1 is entered
    while (1) {
        scanf("%d", &num);
        if (num == -1) break;
        count++;

        // Create a new node for the input number
        Node* newNode = insertSorted(num);

        // Check if number is even
        if (num % 2 == 0)
        {
            // Add node to even list (handle head and tail)
            if (*evenHead == NULL)
            {
                *evenHead = evenTail = newNode;
            }
            else
            {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        else
        {
            // Check if number is odd
            // Add node to odd list (handle head and tail)
            if (*oddHead == NULL)
            {
                *oddHead = oddTail = newNode;
            }
            else
            {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        }
    }
    return count;
}

// Prints the elements of a linked list
void printList(Node* head) {
    // Check if the list is empty
    if (head == NULL) {
        printf("הרשימה ריקה.\n");
        return;
    }

    // Print each node's data
    while (head != NULL) {
        printf("%d → ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Frees all memory allocated for the linked list
void freeList(Node* head) {
    // Traverse the list and free each node
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

