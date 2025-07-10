/* The program creates dynamic sorted array without duplications
   by means of three functions  */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

#define N 10

   //Prototypes
void output(int arr[], int size); //shows content of array
int* RemoveDup_1(int arr[], int size, int* ptr_new_size);
int RemoveDup_2(int arr[], int size, int** ptr_arr_new);
void RemoveDup_3(int arr[], int size, int** ptr_arr_new, int* ptr_new_size);

void main()
{
	int a[N] = { 57,70,70,76,88,88,88,88,98,98 }, * b, new_size;

	printf("Initial array: ");
	output(a, N);

	b = RemoveDup_1(a, N, &new_size);
	printf("\nThe size of new array is %d\n", new_size);
	printf("New array: ");
	output(b, new_size);
	free(b);

	new_size = RemoveDup_2(a, N, &b);
	printf("\nThe size of new array is %d\n", new_size);
	printf("New array: ");
	output(b, new_size);
	free(b);

	RemoveDup_3(a, N, &b, &new_size);
	printf("\nThe size of new array is %d\n", new_size);
	printf("New array: ");
	output(b, new_size);
	free(b);
}

void output(int arr[], int size) //shows content of array
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

int* RemoveDup_1(int arr[], int size, int* ptr_new_size)
{
	int i, j, * arr_new;
	*ptr_new_size = 1;

	// Estimation of new array's size
	for (i = 1; i < size; i++)
		if (arr[i] != arr[i - 1])
			(*ptr_new_size)++;

	// allocation of new array
	arr_new = (int*)calloc(*ptr_new_size, sizeof(int));

	// copying initial array to new array without duplications
	arr_new[0] = arr[0];
	for (i = 1, j = 0; i < size; i++)
		if (arr[i] != arr[i - 1])
			arr_new[++j] = arr[i];
	
	return arr_new;
}


int RemoveDup_2(int arr[], int size, int** ptr_arr_new)
{
	int i, j, new_size = 1;

	// Estimation of new array's size
	for (i = 1; i < size; i++)
		if (arr[i] != arr[i - 1])
			new_size++;

	// allocation of new array
	*ptr_arr_new = (int*)calloc(new_size, sizeof(int));

	// copying initial array to new array without duplications
	(*ptr_arr_new)[0] = arr[0];
	for (i = 1, j = 0; i < size; i++)
		if (arr[i] != arr[i - 1])
			(*ptr_arr_new)[++j] = arr[i];

	return new_size;
}


void RemoveDup_3(int arr[], int size, int** ptr_arr_new, int* ptr_new_size)
{
	int i, j;
	*ptr_new_size = 1;

	// Estimation of new array's size
	for (i = 1; i < size; i++)
		if (arr[i] != arr[i - 1])
			(*ptr_new_size)++;

	// allocation of new array
	*ptr_arr_new = (int*)calloc(*ptr_new_size, sizeof(int));

	// copying initial array to new array without duplications
	(*ptr_arr_new)[0] = arr[0];
	for (i = 1, j = 0; i < size; i++)
		if (arr[i] != arr[i - 1])
			(*ptr_arr_new)[++j] = arr[i];
}