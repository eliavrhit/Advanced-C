#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void SeparateEvenOdd(int *arr, int size, int **evenArr, int *evenSize, int **oddArr, int *oddSize) {
    *evenSize = 0;
    *oddSize = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) (*evenSize)++;
        else (*oddSize)++;
    }
    *evenArr = (int *)malloc((*evenSize) * sizeof(int));
    *oddArr = (int *)malloc((*oddSize) * sizeof(int));
    int e = 0, o = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) (*evenArr)[e++] = arr[i];
        else (*oddArr)[o++] = arr[i];
    }
}

void SeparateCase(char *arr, char **lowercase, char **uppercase) {
    int lowerCount = 0, upperCount = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (islower(arr[i])) lowerCount++;
        else if (isupper(arr[i])) upperCount++;
    }
    *lowercase = (char *)malloc((lowerCount + 1) * sizeof(char));
    *uppercase = (char *)malloc((upperCount + 1) * sizeof(char));
    int l = 0, u = 0;
    for (int i = 0; arr[i] != '\0'; i++) {
        if (islower(arr[i])) (*lowercase)[l++] = arr[i];
        else if (isupper(arr[i])) (*uppercase)[u++] = arr[i];
    }
    (*lowercase)[l] = '\0';
    (*uppercase)[u] = '\0';
}

void PrintArr(int *arr, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

// Version 4a - scan first, return new array, size by reference
int* RemoveDupV4a_Scan(int *arr, int size, int *newSize) {
    if (size == 0) {
        *newSize = 0;
        return NULL;
    }
    int count = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i-1]) count++;
    }
    int *res = (int *)malloc(count * sizeof(int));
    res[0] = arr[0];
    int idx = 1;
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i-1]) res[idx++] = arr[i];
    }
    *newSize = count;
    return res;
}

// Version 4a - realloc version
int* RemoveDupV4a_Realloc(int *arr, int size, int *newSize) {
    if (size == 0) {
        *newSize = 0;
        return NULL;
    }
    int *res = (int *)malloc(sizeof(int));
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || arr[i] != arr[i-1]) {
            res = (int *)realloc(res, (count + 1) * sizeof(int));
            res[count++] = arr[i];
        }
    }
    *newSize = count;
    return res;
}

// Version 4b - scan first, returns size, array by reference
int RemoveDupV4b_Scan(int **arr, int size) {
    if (size == 0) {
        *arr = NULL;
        return 0;
    }
    int count = 1;
    for (int i = 1; i < size; i++) {
        if ((*arr)[i] != (*arr)[i-1]) count++;
    }
    int *res = (int *)malloc(count * sizeof(int));
    res[0] = (*arr)[0];
    int idx = 1;
    for (int i = 1; i < size; i++) {
        if ((*arr)[i] != (*arr)[i-1]) res[idx++] = (*arr)[i];
    }
    free(*arr);
    *arr = res;
    return count;
}

// Version 4b - realloc version
int RemoveDupV4b_Realloc(int **arr, int size) {
    if (size == 0) {
        *arr = NULL;
        return 0;
    }
    int *res = (int *)malloc(sizeof(int));
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0 || (*arr)[i] != (*arr)[i-1]) {
            res = (int *)realloc(res, (count + 1) * sizeof(int));
            res[count++] = (*arr)[i];
        }
    }
    free(*arr);
    *arr = res;
    return count;
}

// Version 4c - scan first, returns nothing, array and size by reference
void RemoveDupV4c_Scan(int **arr, int *size) {
    if (*size == 0) {
        free(*arr);
        *arr = NULL;
        return;
    }
    int count = 1;
    for (int i = 1; i < *size; i++) {
        if ((*arr)[i] != (*arr)[i-1]) count++;
    }
    int *res = (int *)malloc(count * sizeof(int));
    res[0] = (*arr)[0];
    int idx = 1;
    for (int i = 1; i < *size; i++) {
        if ((*arr)[i] != (*arr)[i-1]) res[idx++] = (*arr)[i];
    }
    free(*arr);
    *arr = res;
    *size = count;
}

// Version 4c - realloc version
void RemoveDupV4c_Realloc(int **arr, int *size) {
    if (*size == 0) {
        free(*arr);
        *arr = NULL;
        *size = 0;
        return;
    }
    int *res = (int *)malloc(sizeof(int));
    int count = 0;
    for (int i = 0; i < *size; i++) {
        if (i == 0 || (*arr)[i] != (*arr)[i-1]) {
            res = (int *)realloc(res, (count + 1) * sizeof(int));
            res[count++] = (*arr)[i];
        }
    }
    free(*arr);
    *arr = res;
    *size = count;
}

int main() {
    // Task 1: sum of even numbers from -2 to 20
    int sum = 0;
    for (int i = -2; i <= 20; i++) {
        if (i % 2 == 0) sum += i;
    }
    printf("Sum of even numbers from -2 to 20: %d\n", sum);

    // Task 2: Separate even and odd numbers from array
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int *evenArr, *oddArr;
    int evenSize, oddSize;
    SeparateEvenOdd(arr, size, &evenArr, &evenSize, &oddArr, &oddSize);
    printf("Even numbers: ");
    PrintArr(evenArr, evenSize);
    printf("Odd numbers: ");
    PrintArr(oddArr, oddSize);
    free(evenArr);
    free(oddArr);

    // Task 3: Separate lowercase and uppercase letters
    char text[] = "Hello World! This Is A Test.";
    char *lowercase, *uppercase;
    SeparateCase(text, &lowercase, &uppercase);
    printf("Lowercase letters: %s\n", lowercase);
    printf("Uppercase letters: %s\n", uppercase);
    free(lowercase);
    free(uppercase);

    // Task 4: Remove duplicates from sorted array

    // Original sorted array with duplicates
    int sortedArr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 6};
    int sortedSize = sizeof(sortedArr) / sizeof(sortedArr[0]);

    // 4a Scan version
    int newSize4a_scan;
    int *res4a_scan = RemoveDupV4a_Scan(sortedArr, sortedSize, &newSize4a_scan);
    printf("4a Scan version result: ");
    PrintArr(res4a_scan, newSize4a_scan);
    free(res4a_scan);

    // 4a Realloc version
    int newSize4a_realloc;
    int *res4a_realloc = RemoveDupV4a_Realloc(sortedArr, sortedSize, &newSize4a_realloc);
    printf("4a Realloc version result: ");
    PrintArr(res4a_realloc, newSize4a_realloc);
    free(res4a_realloc);

    // 4b Scan version
    int *arr4b_scan = (int *)malloc(sortedSize * sizeof(int));
    for (int i = 0; i < sortedSize; i++) arr4b_scan[i] = sortedArr[i];
    int newSize4b_scan = RemoveDupV4b_Scan(&arr4b_scan, sortedSize);
    printf("4b Scan version result: ");
    PrintArr(arr4b_scan, newSize4b_scan);
    free(arr4b_scan);

    // 4b Realloc version
    int *arr4b_realloc = (int *)malloc(sortedSize * sizeof(int));
    for (int i = 0; i < sortedSize; i++) arr4b_realloc[i] = sortedArr[i];
    int newSize4b_realloc = RemoveDupV4b_Realloc(&arr4b_realloc, sortedSize);
    printf("4b Realloc version result: ");
    PrintArr(arr4b_realloc, newSize4b_realloc);
    free(arr4b_realloc);

    // 4c Scan version
    int *arr4c_scan = (int *)malloc(sortedSize * sizeof(int));
    for (int i = 0; i < sortedSize; i++) arr4c_scan[i] = sortedArr[i];
    int size4c_scan = sortedSize;
    RemoveDupV4c_Scan(&arr4c_scan, &size4c_scan);
    printf("4c Scan version result: ");
    PrintArr(arr4c_scan, size4c_scan);
    free(arr4c_scan);

    // 4c Realloc version
    int *arr4c_realloc = (int *)malloc(sortedSize * sizeof(int));
    for (int i = 0; i < sortedSize; i++) arr4c_realloc[i] = sortedArr[i];
    int size4c_realloc = sortedSize;
    RemoveDupV4c_Realloc(&arr4c_realloc, &size4c_realloc);
    printf("4c Realloc version result: ");
    PrintArr(arr4c_realloc, size4c_realloc);
    free(arr4c_realloc);

    return 0;
}
