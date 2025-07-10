#include <stdio.h>
#include <malloc.h>

#define N 5

int** create_lower_matrix(int n);
int lower_matr_element(int** a, int i, int j);
void print_lower_matrix(int** a, int n);
int** create_upper_matrix(int n);
int upper_matr_element(int** a, int i, int j);
void print_upper_matrix(int** a, int n);
void free_matrix(int** a, int n);

void main()
{
	int** low_mat, ** up_mat;

	low_mat = create_lower_matrix(N);
	printf("Lower-Triangular Matrix\n");
	print_lower_matrix(low_mat, N);

	up_mat = create_upper_matrix(N);
	printf("\nUpper-Triangular Matrix\n");
	print_upper_matrix(up_mat, N);

	free_matrix(low_mat, N);
	free_matrix(up_mat, N);
}

int** create_lower_matrix(int n)
{
	int** a, i, j;
	a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		a[i] = (int*)calloc(i + 1, sizeof(int));
	for (i = 0; i < n; i++)
		for (j = 0; j <= i; j++)
			a[i][j] = i + j + 2;
	return a;
}

int lower_matr_element(int** a, int i, int j)
{
	if (i >= j)
		return a[i][j];
	return 0;
}

void print_lower_matrix(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%8d", lower_matr_element(a, i, j));
		printf("\n");
	}
}

int** create_upper_matrix(int n)
{
	int** a, i, j;
	a = (int**)calloc(n, sizeof(int*));
	for (i = 0; i < n; i++)
		a[i] = (int*)calloc(n - i, sizeof(int));
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i; j++)
			a[i][j] = 2 * i + j + 2;
	return a;
}

int upper_matr_element(int** a, int i, int j)
{
	if (i <= j)
		return a[i][j - i];
	return 0;
}

void print_upper_matrix(int** a, int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			printf("%8d", upper_matr_element(a, i, j));
		printf("\n");
	}
}

void free_matrix(int** a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(a[i]);
	free(a);
}

