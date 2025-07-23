#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct item
{
    int number;
    struct item *next;
} Item;

Item **ex1(int *A, int sz, int *p_size)
{
    int *digits = (int *)calloc(sz, sizeof(int));
    int i;
    *p_size = 1;
    for (i = 0; i < sz; i++)
    {
        digits[i] = digitsNumber(A[i]);
        if (digits[i] > *p_size)
        {
            *p_size = digits[i];
        }
    }
    Item **L = (Item **)calloc(*p_size, sizeof(Item *));
    Item *curr = NULL;
    for (i = sz - 1; i >= 0; i--)
    {
        curr = (Item *)malloc(sizeof(Item));
        curr->number = A[i];
        curr->next = L[digits[i] - 1];
        L[digits[i] - 1] = curr;
    }
    free(digits);
    return L;
}

int digitsNumber(int num)
{
    int count = 1;
    num = abs(num);
    while (num > 9)
    {
        count++;
        num /= 10;
    }
    return count;
}

int **ex2(int **M, int rows, int cols)
{
    int **F = (int **)calloc(rows + 2, sizeof(int *));
    int row, col;
    for (row = 0; row < rows + 2; row++)
    {
        F[row] = (int *)calloc(cols + 2, sizeof(int));
    }
    for (row = 0; row < rows; row++)
    {
        for (col = 0; col < cols; col++)
        {
            F[row + 1][col + 1] = M[row][col];
        }
    }
    for (row = 0; row < rows; rows++) {
        free(M[row]);
    }
    free(M);
    return F;
}

void ex3(const char* inputFilename, const char* outputFilename) {
    FILE *fin = fopen(inputFilename, "r");
    if (!fin)
    {
        exit(1);
    }
    FILE *fout = fopen(outputFilename, "w");
    if (!fout)
    {
        fclose(fin);
        exit(1);
    }
    char str[101];
    while (fgets(str, 101, fin)) {
        str[strlen(str) - 1] = '\0';
        if (hasUniqueLetters(str) == 1) {
            reverseString(str);
            fprintf(fout, "%s\n", str);
        }
    }
    fclose(fin);
    fclose(fout);
}

int hasUniqueLetters(const char* str) {
    int monim[26] = {0};
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        if (!isalpha(str[i])) {
            return 0;
        }
        if (monim[tolower(str[i]) - 'a'] > 0) {
            return 0;
        }
        monim[tolower(str[i]) - 'a'] = 1;
    }
    return 1;
}

void reverseString(char* str) {
    int i, len = strlen(str);
    char temp;
    for (i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}