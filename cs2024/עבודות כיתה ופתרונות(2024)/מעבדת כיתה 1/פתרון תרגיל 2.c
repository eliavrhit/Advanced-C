/*The program creates two dynamic arrays:
one of capital letters and one of small letters*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void Capital_small(char* a, int size, char** Cap, int* Cap_size, char** small, int* small_size);
void output(char arr[], int size); //shows content of array

#define N 10

void main()
{
	char arr[N], * arr_Cap, * arr_small;
	int n_Cap, n_small, i;

	printf("Enter array: ");
	for (i = 0; i < N; i++)
		arr[i] = getchar();

	Capital_small(arr, N, &arr_Cap, &n_Cap, &arr_small, &n_small);

	printf("\n%d CAPITAL letters (address of array %p): ", n_Cap, arr_Cap);
	output(arr_Cap, n_Cap);
	printf("\n%d small letters (address of array %p): ", n_small, arr_small);
	output(arr_small, n_small);

	free(arr_Cap);
	free(arr_small);
}

void Capital_small(char* a, int size, char** Cap, int* Cap_size, char** small, int* small_size)
{
	int i_Cap, i_small, i;

	*Cap_size = *small_size = 0;
	for (i = 0; i < size; i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			(*Cap_size)++;
		else
			if (a[i] >= 'a' && a[i] <= 'z')
				(*small_size)++;
	*Cap = (char*)malloc(*Cap_size);
	*small = (char*)malloc(*small_size);
	i_Cap = i_small = 0;
	for (i = 0; i < size; i++)
		if (a[i] >= 'A' && a[i] <= 'Z')
			(*Cap)[i_Cap++] = a[i];
		else
			if (a[i] >= 'a' && a[i] <= 'z')
				(*small)[i_small++] = a[i];
}

void output(char arr[], int size) //shows content of array
{
	int i;
	for (i = 0; i < size; i++)
		printf("%c ", arr[i]);
	printf("\n");
}







