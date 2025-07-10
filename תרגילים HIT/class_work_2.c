#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

int* splitArray (int A[], int size, int** oddArray, int* countEven, int* countOdd);
void splitChars (char original[], int size, char** lowercase, char** uppercase, int* countLower, int* countUpper);
void splitChars2 (char  *original, int size, char** lowercase, char** uppercase);

/* ex1
int main() {

    int size = N;
    int A[size];
    printf("Please enter array elements: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &A[i]);
    }
    int countEven, countOdd;
    int* oddArray;
    int* evenArray = splitArray(A, size, &oddArray, &countEven, &countOdd);
    printf("The first array: \n");
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    printf("Even array elements: \n");
    for (int i = 0; i < countEven; i++) {
        printf("%d ", evenArray[i]);
    }
    printf("\n");
    printf("Odd array elements: \n");
    for (int i = 0; i < countOdd; i++) {
        printf("%d ", oddArray[i]);
    }
    free(oddArray);
    free(evenArray);

    return 0;
}

int* splitArray (int A[], int size, int** oddArray, int* countEven, int* countOdd) {

    *countEven = 0, *countOdd = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] % 2 == 0) {
            (*countEven)++;
        }
        else {
            (*countOdd)++;
        }
    }
    *oddArray = (int*)malloc((*countOdd)*sizeof(int));
    int *evenArray = (int*)malloc((*countEven)*sizeof(int));
    int even_index = 0, odd_index = 0;
    for (int i = 0; i < size; i++) {
        if (A[i] % 2 == 0) {
            evenArray[even_index] = A[i];
            even_index++;
        }
        else {
            (*oddArray)[odd_index] = A[i];
            odd_index++;
        }
    }
    return evenArray;

}
*/

/* ex2
int main() {

    int countLower, countUpper;
    char original[] = {"AbCdEfGhIj"}, *lowercase, *uppercase;
    int size = strlen(original);
    splitChars(original, size, &lowercase, &uppercase, &countLower, &countUpper);
    printf("Original string: %s\n", original);
    for (int i = 0; i < size; i++) {
        printf("%c", original[i]);
    }
    printf("\n");
    printf("Lowercase string: \n");
    for (int i = 0; i < countLower; i++) {
        printf("%c", lowercase[i]);
    }
    printf("\n");
    printf("Uppercase string: \n");
    for (int i = 0; i < countUpper; i++) {
        printf("%c", uppercase[i]);
    }
    free(lowercase);
    free(uppercase);

    return 0;
}

void splitChars (char original[], int size, char** lowercase, char** uppercase, int* countLower, int* countUpper) {

    *countLower = *countUpper = 0;
    for (int i = 0; i < size; i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            (*countLower)++;
        }
        else if (original[i] >= 'A' && original[i] <= 'Z') {
            (*countUpper)++;
        }
    }
    *lowercase = (char*) malloc(((*countLower) * sizeof(char)));
    *uppercase = (char*) malloc(((*countUpper) * sizeof(char)));
    int lowerCaseIndex = 0, upperCaseIndex = 0;
    for (int i = 0; i < size; i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            (*lowercase)[lowerCaseIndex] = original[i];
            lowerCaseIndex++;
        }
        else if (original[i] >= 'A' && original[i] <= 'Z') {
            (*uppercase)[upperCaseIndex] = original[i];
            upperCaseIndex++;
        }
    }

}*/


/* ex3 */
int main() {

    //initializing & allocating
    int size = N;
    char* original = (char*)calloc((size + 1) , sizeof(char));
    printf("Enter string: ");
    fgets(original, size + 1, stdin);
    char *lowercase, *uppercase;
    //call function
    splitChars2(original, size, &lowercase, &uppercase);
    //printing
    printf("Lowercase: %s\n", lowercase);
    printf("Uppercase: %s\n", uppercase);
    //freeing allocating
    free(original);
    free(lowercase);
    free(uppercase);

    return 0;
}

void splitChars2 (char  *original, int size, char** lowercase, char** uppercase) {

    int countLower = 0, countUpper = 0;
    for (int i = 0; i < size; i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            countLower++;
        }
        else if (original[i] >= 'A' && original[i] <= 'Z') {
            countUpper++;
        }
    }
    *lowercase = (char*)calloc((countLower + 1) , sizeof(char));
    *uppercase = (char*)calloc((countUpper + 1) , sizeof(char));
    int lowerCaseIndex = 0, upperCaseIndex = 0;
    for (int i = 0; i < size; i++) {
        if (original[i] >= 'a' && original[i] <= 'z') {
            (*lowercase)[lowerCaseIndex] = original[i];
            lowerCaseIndex++;
        }
        else if (original[i] >= 'A' && original[i] <= 'Z') {
            (*uppercase)[upperCaseIndex] = original[i];
            upperCaseIndex++;
        }
    }

}