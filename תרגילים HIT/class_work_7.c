#include <stdio.h>
#include <stdlib.h>

//ex1

void swapRows(int** matrix, int row1, int row2);
void swapCols(int** matrix, int rows, int col1, int col2);
void printMatrix(int** matrix, int rows, int cols);
void freeMatrix(int** matrix, int rows);

int main() {
    int rows = 3,  cols = 3;
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    matrix[0][0] = 1;
    matrix[0][1] = 2;
    matrix[0][2] = 3;
    matrix[1][0] = 4;
    matrix[1][1] = 5;
    matrix[1][2] = 6;
    matrix[2][0] = 7;
    matrix[2][1] = 8;
    matrix[2][2] = 9;
    printMatrix(matrix, rows, cols);
    swapRows(matrix, 0, 2);
    printf("\n");
    printMatrix(matrix, rows, cols);
    swapCols(matrix, rows, 0, 2);
    printf("\n");
    printMatrix(matrix, rows, cols);
    freeMatrix(matrix, rows);
    matrix = NULL;
    printf("\n");
    printMatrix(matrix, rows, cols);

    return 0;
}

void printMatrix(int** matrix, int rows, int cols) {

    if (matrix == NULL) {
        printf("matrix is empty!\n");
        return;
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
}

void swapRows(int** matrix, int row1, int row2) {

    int* temp = matrix[row1];
    matrix[row1] = matrix[row2];
    matrix[row2] = temp;

}

void swapCols(int** matrix, int rows, int col1, int col2) {

    int temp = 0;
    for (int i = 0; i < rows; i++)
    {
        temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

void freeMatrix(int** matrix, int rows) {

    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

}