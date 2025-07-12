#include <stdio.h>
#include <stdlib.h>

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
    // Create a lower-triangular matrix of size N
    int** low_mat, ** up_mat;

    low_mat = create_lower_matrix(N);
    // Print the lower-triangular matrix
    printf("Lower-Triangular Matrix\n");
    print_lower_matrix(low_mat, N);

    // Create an upper-triangular matrix of size N
    up_mat = create_upper_matrix(N);
    // Print the upper-triangular matrix
    printf("\nUpper-Triangular Matrix\n");
    print_upper_matrix(up_mat, N);

    // Free the memory allocated for the lower-triangular matrix
    free_matrix(low_mat, N);
    // Free the memory allocated for the upper-triangular matrix
    free_matrix(up_mat, N);
}

int** create_lower_matrix(int n)
{
    int** a, i, j;
    // Allocate memory for n pointers to int arrays (rows)
    a = (int**)calloc(n, sizeof(int*));
    // For each row i, allocate memory for i+1 elements (columns) to store lower-triangular elements
    for (i = 0; i < n; i++)
        a[i] = (int*)calloc(i + 1, sizeof(int));
    // Fill the lower-triangular matrix elements with values based on i and j
    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            a[i][j] = i + j + 2;
    // Return the pointer to the lower-triangular matrix
    return a;
}

int lower_matr_element(int** a, int i, int j)
{
    // If the element is in the lower triangle (row >= column), return the stored value
    if (i >= j)
        return a[i][j];
    // Otherwise, return 0 since it's outside the lower triangle
    return 0;
}

void print_lower_matrix(int** a, int n)
{
    int i, j;
    // Iterate over each row
    for (i = 0; i < n; i++)
    {
        // Iterate over each column in the row
        for (j = 0; j < n; j++)
            // Print the element at position (i, j) using lower_matr_element to handle zeros outside the lower triangle
            printf("%8d", lower_matr_element(a, i, j));
        // Print a newline after each row
        printf("\n");
    }
}

int** create_upper_matrix(int n)
{
    int** a, i, j;
    // Allocate memory for n pointers to int arrays (rows)
    a = (int**)calloc(n, sizeof(int*));
    // For each row i, allocate memory for n - i elements to store upper-triangular elements
    for (i = 0; i < n; i++)
        a[i] = (int*)calloc(n - i, sizeof(int));
    // Fill the upper-triangular matrix elements with values based on i and j
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i; j++)
            a[i][j] = 2 * i + j + 2;
    // Return the pointer to the upper-triangular matrix
    return a;
}

int upper_matr_element(int** a, int i, int j)
{
    // If the element is in the upper triangle (row <= column), return the stored value
    if (i <= j)
        return a[i][j - i];
    // Otherwise, return 0 since it's outside the upper triangle
    return 0;
}

void print_upper_matrix(int** a, int n)
{
    int i, j;
    // Iterate over each row
    for (i = 0; i < n; i++)
    {
        // Iterate over each column in the row
        for (j = 0; j < n; j++)
            // Print the element at position (i, j) using upper_matr_element to handle zeros outside the upper triangle
            printf("%8d", upper_matr_element(a, i, j));
        // Print a newline after each row
        printf("\n");
    }
}

void free_matrix(int** a, int n)
{
    int i;
    // Free each row's allocated memory
    for (i = 0; i < n; i++)
        free(a[i]);
    // Free the array of pointers to rows
    free(a);
}
