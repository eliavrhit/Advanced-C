#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*ex1

typedef struct item {
    int number;
    struct item* next;
} Item;

Item ** numSeparation(int * A, int sz, int * p_size);
int digitsNumber(int num);

int main() {
    // Initialize array A with example values
    int A[] = {23, 4, -78, 34578, 79, -185, 0, 998, 9, 36};
    int sz = sizeof(A) / sizeof(A[0]); // Calculate size of array A
    int p_size;

    // Call function to separate numbers by digit count
    Item **result = numSeparation(A, sz, &p_size);

    // Print the resulting linked lists grouped by number of digits
    for (int i = 0; i < p_size; i++) {
        printf("Group %d digits: ", i + 1);
        Item *curr = result[i];
        while (curr) {
            printf("%d ", curr->number);
            curr = curr->next;
        }
        printf("\n");
    }

    // Free all allocated memory
    for (int i = 0; i < p_size; i++) {
        Item *curr = result[i];
        while (curr) {
            Item *tmp = curr;
            curr = curr->next;
            free(tmp);
        }
    }
    free(result);
    return 0;
}

Item ** numSeparation(int * A, int sz, int * p_size) {

    // Allocate array to hold digit counts for each number in A
    int* digits = (int*)calloc(sz, sizeof(int));
    *p_size = 1;

    // First loop: calculate digit count for each number and find max digit count
    for (int i = 0; i < sz; i++) {
        digits[i] = digitsNumber(A[i]);  // get number of digits
        if (digits[i] > *p_size) {
            *p_size = digits[i];  // track maximum digit count
        }
    }

    int n = *p_size;

    // Allocate array of linked list heads, one per digit group
    Item** L = (Item**)calloc(n, sizeof(Item*));
    Item* curr = NULL;

    // Second loop: create linked list nodes and insert into appropriate group
    for (int i = 0; i < sz; i++) {
        curr = (Item*)malloc(sizeof(Item));
        curr->number = A[i];
        // Insert at the head of the corresponding digit-count list (adjusted index)
        curr->next = L[digits[i] - 1];
        L[digits[i] - 1] = curr;
    }
    free(digits); // free temporary digits array
    return L;
}

int digitsNumber(int num) {

    int count = 0;
    num = abs(num);
    if (num == 0) {
        count = 1;
        return count;
    }
    while (num) {
        num = num / 10;
        count++;
    }
    return count;
} */

/*ex2

int ** matrixToFrame(int ** M, int rows, int cols);

int main() {
    int rows = 3, cols = 4;

    // Allocate and populate matrix M with values from the question
    int** M = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        M[i] = (int*)malloc(cols * sizeof(int));
    }

    // Manually fill in M according to the question
    int values[3][4] = {
        {16, 4, 67, 200},
        {57, 2, 123, -7},
        {11, 9, 34, 109}
    };

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            M[i][j] = values[i][j];
        }
    }

    //print M
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Call the function
    int** F = matrixToFrame(M, rows, cols);

    // Free matrix F
    for (int i = 0; i < rows + 2; i++) {
        free(F[i]);
    }
    free(F);

    return 0;
}

int ** matrixToFrame(int ** M, int rows, int cols) {

    //rows - 3, cols = 4

    //הקצאה של מצביע למצביע F עם 5 שורות
    int** F = (int**)calloc(rows + 2 ,sizeof(int*));

    //הקצאה של 6 עמודות לכל שורה
    for (int row = 0; row < rows + 2; row++) {
        F[row] = (int*)calloc(cols + 2, sizeof(int));
    }

    //מילוי F
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            F[row + 1][col + 1] = M[row][col];
        }
    }

    // Print the resulting matrix F
    for (int i = 0; i < rows + 2; i++) {
        for (int j = 0; j < cols + 2; j++) {
            printf("%4d", F[i][j]);
        }
        printf("\n");
    }

    //free M
    for (int row = 0; row < rows; row++) {
        free(M[row]);
    }
    free(M);

    return F;
} */


/*ex3

void processFiles(const char* inputFilename, const char* outputFilename);
void reverseString(char* str);
int hasUniqueLetters(const char* str);

int main() {

    processFiles("Files/2input.txt", "Files/2output.txt");
    return 0;
}

void processFiles(const char* inputFilename, const char* outputFilename) {

    FILE* input;
    FILE* output;
    input = fopen(inputFilename, "r");
    if (input == NULL) {
        printf("input file cannot be open \n");
        exit(1);
    }
    output = fopen(outputFilename, "w");
    if (output == NULL) {
        fclose(input);
        printf("output file cannot be open \n");
        exit(1);
    }
    char str[101];
    while (fscanf(input, "%s", str) != EOF) {
        if (hasUniqueLetters(str) == 1) {
            printf("the word %s is valid \n", str);
            reverseString(str);
            fprintf(output, "%s\n", str);
        }
        else {
            printf("the word %s is not valid \n", str);
        }
    }
    fclose(input);
    fclose(output);
}

void reverseString(char* str) {

    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int hasUniqueLetters(const char* str) {

    // 1. מכילה רק אותיות | 2. כל האותיות שונות

    int letters[26] = {0}, i;
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            if (letters[str[i] - 'a'] > 0) {
                return 0;
            }
            letters[str[i] - 'a']++;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            if (letters[str[i] - 'A'] > 0) {
                return 0;
            }
            letters[str[i] - 'A']++;
        }
        else {
            return 0;
        }
    }

    return 1;
}
*/

/*ex4*/

// x=2 y=2
// x=4 y=2
// x=2 y=5
// x=6 y=5
// x=6 y=7
//הסבר באייפד

/*ex5*/

// 4
// 1


/*ex6*/


