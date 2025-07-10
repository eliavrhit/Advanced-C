/* The program swaps rows and columns in dynamic matrix */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void alloc_matrix(int** c, int rows, int cols);
void free_matrix(int** c, int n);
void print_din_matrix(int** a, int rows, int cols);
void point_swap(void** p, void** q);
void rows_swap(void** matr, int row1, int row2);
void columns_swap(int** matr, int column1, int column2, int rows_num);

#define N 4

void main()
{
	int* arr[N], n_cols, i, j, count = 0;

	printf("Enter the number of columns in matrix  ");
	scanf("%d", &n_cols);

	alloc_matrix(arr, N, n_cols);
	for (i = 0; i < N; i++)
		for (j = 0; j < n_cols; j++)
		{
			arr[i][j] = count;
			count++;
		}
	print_din_matrix(arr, N, n_cols);

	do
	{
		printf("Enter rows for swap  ");
		scanf("%d%d", &i, &j);
	} while (i < 0 || i >= N || j < 0 || j >= N);
	rows_swap(arr, i, j);
	print_din_matrix(arr, N, n_cols);

	do
	{
		printf("Enter columns for swap  ");
		scanf("%d%d", &i, &j);
	} while (i < 0 || i >= n_cols || j < 0 || j >= n_cols);
	columns_swap(arr, i, j, N);
	print_din_matrix(arr, N, n_cols);

	free_matrix(arr, N);
}

void alloc_matrix(int** c, int rows, int cols)
{
	int i;
	for (i = 0; i < rows; i++)
		c[i] = (int*)calloc(cols, sizeof(int));
}

void free_matrix(int** c, int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(c[i]);
}

void print_din_matrix(int** a, int rows, int cols)
{
	int i, j;
	printf("\n");
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
			printf("%8d", a[i][j]);
		printf("\n");
	}
	printf("\n");
}

void point_swap(void** p, void** q)
{
	void* temp = *p;
	*p = *q;
	*q = temp;
}

void rows_swap(void** matr, int row1, int row2)
{
	point_swap(matr + row1, matr + row2);
}

void columns_swap(int** matr, int column1, int column2, int rows_num)
{
	int temp, i;
	for (i = 0; i < rows_num; i++)
	{
		temp = matr[i][column1];
		matr[i][column1] = matr[i][column2];
		matr[i][column2] = temp;
	}
}