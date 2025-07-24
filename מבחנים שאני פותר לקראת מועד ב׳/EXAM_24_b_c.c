#include <stdio.h>
#include <stdlib.h>

/*ex1

#define COLS 5

typedef struct element {
    int data;
    int col;
    struct element *next;
} element;

element **sparse_matrix_to_lists(int A[][COLS], int rows, int cols);

int main(void) {
    int A[][COLS] = {
        {0, 0, 4, 0, 7},
        {3, 0, 0, 0, 0},
        {9, 1, 0, 6, 0},
        {0, 0, 0, 0, 0}
    };
    int rows = 4, cols = COLS;
    element **lists = sparse_matrix_to_lists(A, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("Row %d:", i);
        for (element *cur = lists[i]; cur != NULL; cur = cur->next) {
            printf(" (%d at col %d)", cur->data, cur->col);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(lists[i]);
    }
    free(lists);
    return 0;
}

element **sparse_matrix_to_lists(int A[][COLS], int rows, int cols) {

    element** lists = (element**)calloc(rows, sizeof(element*));
    element* newNode = NULL;
    for (int row = 0; row < rows; row++) {
        for (int col = cols - 1; col >= 0; col--) {
            if (A[row][col] != 0) {
                newNode = (element*)calloc(1, sizeof(element));
                newNode->data = A[row][col];
                newNode->col = col;
                newNode->next = lists[row];
                lists[row] = newNode;
            }
        }
    }
    return lists;
}
*/

/*ex2*/
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes for exercise 2 */
int is_prime(int num);
int primes_interval(int a, int b, int **primes);

int main() {
    int a, b;
    int *primes = NULL;
    int count;

    printf("please input the first number:\n");
    scanf("%d", &a);
    printf("please input the second number:\n");
    scanf("%d", &b);
    printf("\n");

    /* Call the function to fill the primes array */
    count = primes_interval(a, b, &primes);

    /* Print results */
    if (count > 0) {
        printf("Primes in [%d, %d]:", a, b);
        for (int i = 0; i < count; i++) {
            printf(" %d", primes[i]);
        }
        printf("\n");
        printf("there is %d numbers in count", count);
        free(primes);
    } else {
        printf("No primes found in [%d, %d]\n", a, b);
    }

    return 0;
}

int is_prime(int num) {

    if (num <= 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int primes_interval(int a, int b, int **primes) {

    int* arr = (int*)malloc((b + 1) * sizeof(int));
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (is_prime(i) == 1) {
            arr[count] = i;
            count++;
        }
    }
    *primes = (int*)realloc(arr, sizeof(int) * (count + 1));
    return count;
}

