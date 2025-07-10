#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void *realloc1(void *memblock, unsigned size_old, unsigned size_new);
int *arrcat(int *arr1, unsigned size1, int *arr2, unsigned size2);

void *realloc1(void *memblock, unsigned size_old, unsigned size_new) {
    // cancelling the allocation because the newer size is 0
    if (size_new == 0) {
        free(memblock);
        return NULL;
    }
    // case that memblock = NULL, allocation of new size anyway
    if (memblock == NULL) {
        return malloc(size_new);
    }
    //regular case - allocating new block with malloc of new size, and check if allocation succeed
    void *new_block = malloc(size_new);
    if (new_block == NULL) {
        return NULL;
    }
    //copying old block to new block with the right size
    memcpy(new_block, memblock, size_old < size_new ? size_old : size_new);
    free(memblock);
    return new_block;
}

int *arrcat(int *arr1, unsigned size1, int *arr2, unsigned size2) {
    int *new_arr = realloc1(arr1, size1 * sizeof(int), (size1 + size2) * sizeof(int));
    if (new_arr == NULL) {
        return NULL;
    }
    for (unsigned i = 0; i < size2; ++i) {
        new_arr[size1 + i] = arr2[i];
    }
    return new_arr;
}

int main() {
    int size1 = 3;
    int size2 = 2;

    int *arr1 = malloc(size1 * sizeof(int));
    int *arr2 = malloc(size2 * sizeof(int));

    if (!arr1 || !arr2) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // מילוי ערכים
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;

    arr2[0] = 10;
    arr2[1] = 20;

    // שרשור
    int *result = arrcat(arr1, size1, arr2, size2);
    if (result == NULL) {
        printf("Concatenation failed\n");
        free(arr2);
        return 1;
    }

    // הדפסת תוצאה
    printf("Concatenated array: ");
    for (int i = 0; i < size1 + size2; ++i) {
        printf("%d ", result[i]);
    }
    printf("\n");

    free(result);
    free(arr2);

    return 0;
}
