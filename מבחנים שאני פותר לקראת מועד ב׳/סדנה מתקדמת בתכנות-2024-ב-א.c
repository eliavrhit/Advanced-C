#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*ex1

typedef struct item {
    int digit;
    struct item *next;
} Item;

int numListCmp(Item * L1, Item * L2);
Item* createItem(int digit);
Item* buildListFromInt(int num);

int main() {

    int num1, num2;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    Item* L1 = buildListFromInt(num1);
    Item* L2 = buildListFromInt(num2);

    int result = numListCmp(L1, L2);
    if (result == -1)
        printf("L1 < L2\n");
    else if (result == 1)
        printf("L1 > L2\n");
    else
        printf("L1 == L2\n");

    free(L1);
    free(L2);
    return 0;
}

int numListCmp(Item * L1, Item * L2) {

    int count1 = 0, count2 = 0;
    Item* temp1 = L1;
    Item* temp2 = L2;
    while (temp1 != NULL) {
        count1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }
    if (count1 < count2) {
        return -1;
    }
    else if (count1 > count2) {
        return 1;
    }
    else {
        while (L1 != NULL && L2 != NULL) {
            if (L1->digit < L2->digit) {
                return -1;
            }
            else if (L1->digit > L2->digit) {
                return 1;
            }
            else {
                L1 = L1->next;
                L2 = L2->next;
            }
        }
        return 0;
    }
}

Item* createItem(int digit) {

    Item* newItem = (Item*)malloc(sizeof(Item));
    if (newItem == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newItem->digit = digit;
    newItem->next = NULL;
    return newItem;
}

Item* buildListFromInt(int num) {
    if (num == 0) {
        return createItem(0);
    }

    // נכניס את הספרות למחסנית
    int digits[20]; // מניחים שלא יותר מ-20 ספרות
    int count = 0;
    while (num > 0) {
        digits[count++] = num % 10;
        num /= 10;
    }

    // נבנה את הרשימה מהספרה הכי משמעותית
    Item* head = NULL;
    Item* tail = NULL;

    for (int i = count - 1; i >= 0; i--) {
        Item* newItem = createItem(digits[i]);
        if (head == NULL) {
            head = newItem;
            tail = newItem;
        } else {
            tail->next = newItem;
            tail = newItem;
        }
    }

    return head;
}*/


/*ex2

typedef struct {
    int size;
    int* ptr;
} dyn_array;


dyn_array * divNumbers(int * A, int sz, int n);

int main() {

    int sz = 10, n = 5;

    int A[10] = {15, 49, -8, 6, -25, 9, 10, -58, 1, 77};

    dyn_array* B = divNumbers(A, sz, n);

    for (int i = 0; i < n - 1; i++) {
        printf("B[%d] size: %d\n", i, B[i].size);
        if (B[i].ptr != NULL) {
            for (int j = 0; j < B[i].size; j++) {
                printf("%d ", B[i].ptr[j]);
            }
            printf("\n");
        } else {
            printf("NULL\n");
        }
    }

    // ניקוי זיכרון
    for (int i = 0; i < n - 1; i++) {
        free(B[i].ptr);
    }
    free(B);

    return 0;
}

dyn_array * divNumbers(int * A, int sz, int n) {

    dyn_array* B = (dyn_array*)calloc((n-1) , sizeof(dyn_array));
    int i, j;
    for (i = 2; i <= n; i++) {
        B[i - 2].ptr = (int*)calloc((sz),sizeof(int));
        for (j = 0; j < sz; j++) {
            if ((A[j] % i) == 0) {
                B[i - 2].ptr[B[i - 2].size] = A[j];
                B[i - 2].size += 1;
            }
        }
        B[i - 2].ptr = realloc(B[i - 2].ptr, (B[i - 2].size) * sizeof(int));
    }
    return B;
}
*/

/*ex3

int boggle(char *file_name, char *word);

int main() {

    char* word = "baby";
    int result = boggle("Files/1.txt", word);
    if (result == 0) {
        printf("the word %s isn't exist in file. \n", word);
    }
    else {
        printf("the word %s is exist in file. \n", word);
    }

    return 0;
}


int boggle(char *file_name, char *word) {

    FILE *fp = fopen(file_name, "r");
    if (!fp) {
        exit(1);
    }
    int i = 0;
    char c;
    while ((c = fgetc(fp)) != EOF) {
        if (c == word[0]) {
            i++;
            break;
        }
    }
    if (i == 0) {
        fclose(fp);
        return 0;
    }
    while (word[i] != '\0')
    {
        if ((c = fgetc(fp)) == word[i]) { // right
            i++;
        }
        else { // left
            if (c != EOF) {
                fseek(fp, -1, SEEK_CUR);
            }
            if (ftell(fp) - 2 < 0) {  // there is no letter on left
                fclose(fp);
                return 0;
            }
            fseek(fp, -2, SEEK_CUR); // there is a letter on left so we need to go read it
            if ((c = fgetc(fp)) == word[i]) {
                i++;
            }
            else {
                fclose(fp);
                return 0;
            }
        }
    }
    fclose(fp);
    return 1;
}*/


/*ex4*/

// print 1: 200 400
// print 2: 300 300
// print 3: 400 200
// print 4: 600


/*ex5*/

// answer number 4
// 2 (10) ^ 3 (11) = 1 (01) //XOR

/*ex6*/

