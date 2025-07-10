/*The program creates two dynamic arrays:
one of even numbers and one of odd numbers*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

int* even_odd(int*, int, int**, int*, int*);
void output(int arr[], int size); //shows content of array

#define N 10

void main()
{
	int arr[N], n_even, n_odd, i, * arr_even, * arr_odd;

	printf("Enter array: ");
	for (i = 0; i < N; i++)
		scanf("%d", arr + i);

	arr_even = even_odd(arr, N, &arr_odd, &n_even, &n_odd);

	printf("\n%d Even numbers: ", n_even);
	output(arr_even, n_even);
	printf("\n%d Odd numbers: ", n_odd);
	output(arr_odd, n_odd);
	printf("\n");

	free(arr_even);
	free(arr_odd);
}

int* even_odd(int* a, int size, int** a_odd, int* even_size, int* odd_size)
{
	int* a_even, i, i_even, i_odd;

	*even_size = 0;
	for (i = 0; i < size; i++)
		if (a[i] % 2 == 0)
			(*even_size)++;
	*odd_size = size - *even_size;
	a_even = (int*)calloc(*even_size, sizeof(int));
	*a_odd = (int*)calloc(*odd_size, sizeof(int));
	i_even = i_odd = 0;
	for (i = 0; i < size; i++)
		if (a[i] % 2 == 0)
			a_even[i_even++] = a[i];
		else
			(*a_odd)[i_odd++] = a[i];
	return a_even;
}


void output(int arr[], int size) //shows content of array
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}







