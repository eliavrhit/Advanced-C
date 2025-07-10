#include <stdio.h>
#include <stdlib.h>
/*
int main() {

    int a[10] =  {50, 60, 60, 72, 81, 81, 81, 81, 93, 93};
    printf("this is the first array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    int* b = (int*)malloc(sizeof(int));
    b[0] = a[0];
    int count = 1;
    for (int i = 1; i < 10; i++) {
        if (a[i] != a[i - 1]) {
            count++;
            b = realloc(b, count * sizeof(int));
            b[count - 1] = a[i];
        }
    }
    printf("\n");
    printf("this is the new array: \n");
    for (int i = 0; i < count; i++) {
        printf("%d ", b[i]);
    }
    free(b);

    return 0;
}
*/

int main() {

    int a[10] =  {6, 57, 14, 21, 11, 3, 22, 42, 9, 15};
    int* even = (int*)malloc(sizeof(int));
    int* odd = (int*)malloc(sizeof(int));
    printf("this is the first array: \n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    int countEven = 0, countOdd = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] % 2 == 0) {
            countEven++;
            even = realloc(even, sizeof(int) * countEven);
            even[countEven - 1] = a[i];
        }
        else {
            countOdd++;
            odd = realloc(odd, sizeof(int) * countOdd);
            odd[countOdd - 1] = a[i];
        }
    }
    printf("this is the even array: \n");
    for (int i = 0; i < countEven; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    printf("this is the odd array: \n");
    for (int i = 0; i < countOdd; i++) {
        printf("%d ", odd[i]);
    }
    printf("\n");
    free(even);
    free(odd);
    return 0;
}