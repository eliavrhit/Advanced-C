#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define COLS 5

typedef struct element
{
    int data;
    int col;
    struct element *next;
} element;

element** ex1(int A[][COLS], int rows, int cols) {
    element** arr = (element**)calloc(rows, sizeof(element*));
    element *curr = NULL;
    int row, col;
    for (row = 0; row < rows; row++) {
        for (col = cols - 1; col >= 0; col--) {
            if (A[row][col] != 0) {
                curr = (element*)malloc(sizeof(element));
                curr->data = A[row][col];
                curr->col = col;
                curr->next = arr[row];
                arr[row] = curr;
            }
        }
    }
    return arr;
}

int ex2(int a, int b, int** primes) {
    int count = 0, potentialPrime, i = 0;
    for (potentialPrime = a; potentialPrime <= b; potentialPrime++) {
        if (is_prime(potentialPrime)) {
            count++;
        }
    }
    if (count == 0) {
        *primes = NULL;
        return 0;
    }
    *primes = (int*)malloc(count * sizeof(int));
    for (potentialPrime = a; potentialPrime <= b; potentialPrime++) {
        if (is_prime(potentialPrime)) {
            (*primes)[i] = potentialPrime;
            i++;
        }
    }
    return count;
}

int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    if (num % 2 == 0) {
        return 0;
    }
    int mod;
    for (mod = 3; mod * mod <= num; mod += 2) {
        if (num % mod == 0) {
            return 0;
        }
    }
    return 1;
}

void ex3(char* infile, char* outfile) {
    FILE* fin = fopen(infile, "r");
    if(!fin) {
        exit(1);
    }
    FILE* fout = fopen(outfile, "w");
    if(!fout) {
        fclose(fin);
        exit(1);
    }
    char ch, curr;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch > 'f' && ch <= 'z') {
            fputc(toupper(ch), fout);
        } else if (ch > 'F' && ch <= 'Z') {
            fputc(tolower(ch), fout);
        } else if (isdigit(ch)) { // ch >= '0' && ch <= '9'
            for (curr = '1'; curr <= ch; curr++) {
                fputc(curr, fout);
            }
        } else if (isalpha(ch)) { // (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')
            fprintf(fout, "123456789");
            curr = islower(ch) ? 'a' : 'A';
            for(; curr <= ch; curr++) {
                fputc(curr, fout);
            }
        }
    }
    fclose(fin);
    fclose(fout);
}