#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <complex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/* Constant definitions */

#define N 3
#define ROWS 4
#define COLS 5

/* Type definitions */

// Struct to store a number and the sum of its digits
typedef struct number
{
	unsigned long long num;
	int sum;
} Number;

// Struct to store the i,j and the value of a matrix element
typedef struct triad
{
	int i, j, value;
} Triad;

// Struct for a linked list node containing a Triad and a pointer to the next node
typedef struct item
{
	Triad data;
	struct item* next;
} Item;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int ** matrixMaxNeighbor( int A[][COLS], int rows, int cols);
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);

/* Declarations of auxiliary functions */

int isPrime(int num);
int digitSum(unsigned long long num);

int neighborMax(int A[][COLS], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);

Triad createThree(int i, int j, int value);

void insert(Item** list, Triad Triad_data);

void printArray(Number* arr, int size);
void inputMatrix(int A[][COLS], int rows, int cols);
void printMatrix(int A[][COLS], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void freeMatrix(void** A, int rows);
void inputDynamicMatrix(int** A, int rows, int cols);
void printList(Item* lst);
void freeList(Item* lst);

/* ------------------------------- */

/* Main function: displays a menu and calls the appropriate exercise function based on user input */
int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
		return 0;
}


/* Function definitions */

/* Exercise 1: Find numbers in the range [n1, n2] where the sum of the digits is a prime number */
void Ex1()
{
	unsigned long long n1, n2;
	int size;

	printf("please enter n1: ");
	scanf("%llu", &n1);
	printf("please enter n2: ");
	scanf("%llu", &n2);

	Number* arr_primeNums = primeSums(n1, n2, &size);
	printArray(arr_primeNums, size);
	printf("\n");
	free(arr_primeNums);
}

/* Exercise 2: Create a matrix and compute a new matrix where each element is the maximum neighbor of the corresponding element in the original matrix */
void Ex2()
{
	int** c = NULL;
	int cols, rows;
	int A[ROWS][COLS];

		printf("please enter a valid amount of columns ranging from 1-%d: \n", COLS);
		scanf("%d", &cols);

		printf("please enter a valid amount of rows ranging from 1-%d: \n", ROWS);
		scanf("%d", &rows);


	inputMatrix(A, rows, cols);
	printf("Successfully created matrix A with the following values:\n");
	printf("\n");
	printMatrix(A, rows, cols);

	printf("Printing the new array using the MaxNeighbor function:\n");
	c = matrixMaxNeighbor(A, rows, cols);
	printDynamicMatrix(c, rows, cols);

	printf("\n");
	freeMatrix((void**)c, rows);
}
/* Exercise 3: Create two linked lists from a matrix based on specific conditions */
void Ex3()
{
	Item *pL1 = NULL, *pL2 = NULL;
	int rows, cols;

	printf("please enter amount of rows for the matrix: \n");
	scanf("%d", &rows);
	printf("please enter number of cols for the matrix: \n");
	scanf("%d", &cols);

	int **c = allocMatrix(rows, cols);
	inputDynamicMatrix(c, rows, cols);
	createThreeLists(c, rows, cols, &pL1, &pL2);

	printf("L1:\n");
	printList(pL1);
	printf("L2:\n");
	printList(pL2);

	freeMatrix((void**)c, rows);
	freeList(pL1);
	freeList(pL2);
}
/* Task 1: Finds numbers in the range [n1, n2] where the sum of digits is a prime number, and returns them in an array */
Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
	//initializiation
	unsigned long long i;
	*p_size = 2;
	int amountOf_elements = 0, sumOf_digits, flag = 0;
	Number* arr_primeSums = (Number*) realloc(NULL, (*p_size)*sizeof(Number));

	//check if allocation worked:
	if (!arr_primeSums)
		return NULL;

	//loop that chech whether a number's digit sum i a prime number
	//if yes, will insert to an array make to collect them.

	for (i = n1; i <= n2; i++) {
		sumOf_digits = digitSum(i);
		if(isPrime(sumOf_digits)) {
			//check whether the array is full, if so we resize it *2 so we can insert a new element.
			if(amountOf_elements == *p_size) {
				(*p_size) *= 2;

				arr_primeSums = (Number*) realloc(arr_primeSums, sizeof(Number)*(*p_size));
			}

			//now we know the array has a spot for the new element, let's insert it:
			arr_primeSums[amountOf_elements].num = i;
			arr_primeSums[amountOf_elements].sum = sumOf_digits;
			amountOf_elements++;
			flag = 1;

		}
	}
	*p_size = amountOf_elements;
	arr_primeSums = (Number*) realloc(arr_primeSums, sizeof(Number)*(*p_size));

	if (!flag) {
		arr_primeSums = NULL;
		*p_size = 0;
	}
	return arr_primeSums;
}

/* Task 2: Computes a new matrix where each element is the maximum neighbor of the corresponding element in the original matrix */
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols)
{
	int i,j;
	int** B = allocMatrix(rows,cols);
	for(i = 0; i < rows; i++) {
		for (j = 0; j < cols;j++) {
			B[i][j] = neighborMax(A,rows,cols,i,j);
		}
	}
	return B;

}

/* Task 3: Creates two linked lists from a matrix based on specific conditions */
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2)
{
	int i, j;
	Triad triad_toInsert;
	// Condition: if i + j == A[i][j]
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			if (i + j == A[i][j])
			{
				triad_toInsert = createThree(i, j, i + j);
				insert(pL1, triad_toInsert);
			}
			if (A[i][j] - j == j - i)
			{
				triad_toInsert = createThree(i, j, A[i][j]);
				insert(pL2, triad_toInsert);
			}
		}
	}
}
// task 1 --------------------------------------------------------------------

/* Helper function: Calculates the sum of the digits of a number */
int digitSum(unsigned long long num){
	int sum = 0;
	//algorithm that calculates the sum:

	while(num != 0){
		sum+=num%10;
		num /= 10;
	}
	return sum;
}

/* Helper function: Checks if a number is prime */
int isPrime(int num) {
	int i;

	if (num <= 1)
		return 0;
	//algorithm to get whether a number is prime
	for (i = 2; i*i <= num; i++) {
		if (num%i == 0)
			return 0;
	}
	return 1;
}

/* Prints an array of Numbers */
void printArray(Number* arr, int size) {
	int i;

	if(size == 0) {
		printf("array is empty.");
		return;
	}

	printf("array is: \n [");
	for(i = 0; i < size; i++) {
		printf("num: %llu sum %d",arr[i].num, arr[i].sum);
		if (i != size-1)
			printf(",");
	}
	printf("]");

}

//task 2 --------------------------------------------------------------------------------
/* Inputs a matrix from the user */
void inputMatrix(int A[][COLS], int rows, int cols) {
	int i,j;

	for(i=0; i<rows; i++) {
		for(j=0;j<cols;j++) {
			printf("Enter value for matrix[%d][%d]:", i, j);
			scanf("%d", &A[i][j]);
		}
	}
}

/* Prints a matrix */
void printMatrix(int A[][COLS], int rows, int cols) {
	int i,j;

	for(i=0; i<rows; i++) {
		for(j=0;j<cols;j++) {
			printf("%d ", A[i][j]);
			if(j==cols - 1){
				printf("\n");
			}
		}
	}
	printf("\n");
}

/* Finds the maximum neighbor of a matrix element */
int neighborMax(int A[][COLS], int rows, int cols, int i, int j) {
	int max;
	int initialized = 0;  // Flag to indicate if max has been initialized

	// Check above
	if (i > 0) {
		max = A[i - 1][j];
		initialized = 1;
	}

	// Check below
	if (i < rows - 1) {
		if (!initialized) {
			max = A[i + 1][j];
			initialized = 1;
		} else {
			max = A[i + 1][j] > max ? A[i + 1][j] : max;
		}
	}

	// Check left
	if (j > 0) {
		if (!initialized) {
			max = A[i][j - 1];
			initialized = 1;
		} else {
			max = A[i][j - 1] > max ? A[i][j - 1] : max;
		}
	}

	// Check right
	if (j < cols - 1) {
		if (!initialized) {
			max = A[i][j + 1];
			initialized = 1;
		} else {
			max = A[i][j + 1] > max ? A[i][j + 1] : max;
		}
	}

	return max;
}

/* Allocates memory for a matrix */
int** allocMatrix(int rows, int cols) {
	int i,j;

	//alloc memory for the rows pointers:
	int** matrixAlloc = (int**) calloc(rows,sizeof(int*)) ;
	if (matrixAlloc == NULL) {
		printf("Failed to allocate the matrix\n");
		return NULL;
	}

	//alloc memory for the cols on each row.
	for(i = 0; i < rows; i++) {
		matrixAlloc[i] = (int*) calloc (sizeof(int),cols);
		if (matrixAlloc[i] == NULL) {
			printf("Failed to allocate memory for columns\n");
			// Free already allocated memory before exiting
			freeMatrix((void**)matrixAlloc, i);
			return NULL;
		}
	}

	return matrixAlloc;
}

/* Frees the memory allocated for a matrix */
void freeMatrix(void** A, int rows) {
	int i;

	for (i = 0; i < rows; i++) {
		free(A[i]);
	}
	free(A);
}

//task 3------------------------------

/* Prints a dynamically allocated matrix */
void printDynamicMatrix(int** A, int rows, int cols) {
	int i, j;
	for (i = 0; i < rows; i++)
	{
		printf("\n");
		for (j = 0; j < cols; j++)
		{
			printf("%d ", A[i][j]);
		}
	}
}

/* Creates a Triad struct */
Triad createThree(int i, int j, int value) {
	Triad new_item;
	new_item.i = i;
	new_item.j = j;
	new_item.value = value;

	return new_item;
}

/* Inserts a Triad into a linked list */
void insert(Item** list, Triad Triad_data) {
	Item* new_item = (Item*)malloc(sizeof(Item));
	if (new_item == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	new_item->data = Triad_data;
	new_item->next = NULL;

	if (*list == NULL) {
		*list = new_item;
	} else {
		Item* current = *list;
		while (current->next) {
			current = current->next;
		}
		current->next = new_item;
	}
}

/* Inputs a dynamically allocated matrix from the user */
void inputDynamicMatrix(int** A, int rows, int cols) {

	int i, j;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			printf("Enter value for the matrix at row: %d and col %d: ", i, j);
			scanf("%d", &A[i][j]);
		}
	}
}



/* Prints a linked list */
void printList(Item* lst) {
	while (lst != NULL) {
		printf("->i: %d, j: %d, value: %d\n", lst->data.i, lst->data.j, lst->data.value);
		lst = lst->next;
	}
}

/* Frees the memory allocated for a linked list */
void freeList(Item* lst) {
	Item* temp;
	while (lst != NULL) {
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}