/* The program creates dynamic sorted array without duplications */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

#define N 10

void print_array(int* a, int n);

void main()
{
	int a[N] = { 50, 60, 60, 72, 81, 81, 81, 81, 93, 93 }, count = 1, *new_arr, i;

	for (i = 1; i < N; i++)
		if (a[i] != a[i - 1])
			count++;
	new_arr = (int*)calloc(count, sizeof(int));
	if (!new_arr)
	{
		printf("Not enough memory!");
		return;
	}
	new_arr[0] = a[0];
	count = 1;
	for (i = 1; i < N; i++)
		if (a[i] != a[i - 1])
			new_arr[count++] = a[i];

	printf("Initial array: ");
	print_array(a, N);
	printf("\nNew array: ");
	print_array(new_arr, count);
	printf("\n");

	free(new_arr);
}

void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}




