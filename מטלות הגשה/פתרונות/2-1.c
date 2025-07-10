/*The program creates two dynamic arrays:
one of even numbers and one of odd numbers*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

#define N 10

void print_array(int* a, int n);

void main()
{
	int a[N], even = 0, odd = 0, i, *arr_even, *arr_odd;

	printf("Enter array: ");
	for (i = 0; i < N; i++)
		scanf("%d", a + i);

	for (i = 0; i < N; i++)
		if (a[i] % 2 == 0)
			even++;
	odd = N - even;
	arr_even = (int*)calloc(even, sizeof(int));
	arr_odd = (int*)calloc(odd, sizeof(int));
	if (!arr_even || !arr_odd)
	{
		printf("Not enough memory!");
		return;
	}
	even = odd = 0;
	for (i = 0; i < N; i++)
		if (a[i] % 2 == 0)
			arr_even[even++] = a[i];
		else
			arr_odd[odd++] = a[i];

	printf("\nInitial array: ");
	print_array(a, N);
	printf("\nEven numbers: ");
	print_array(arr_even, even);
	printf("\nOdd numbers: ");
	print_array(arr_odd, odd);
	printf("\n");

	free(arr_even);
	free(arr_odd);
}

void print_array(int* a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}




