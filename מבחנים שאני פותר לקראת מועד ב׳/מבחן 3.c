#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*ex1

#define COLS 5

typedef struct element {
    int data;
    int col;
    struct element *next;
} element;

element **sparse_matrix_to_lists(int A[][COLS], int rows, int cols);

int main(void) {
    int A[][COLS] = {
        {0, 0, 4, 0, 7},
        {3, 0, 0, 0, 0},
        {9, 1, 0, 6, 0},
        {0, 0, 0, 0, 0}
    };
    int rows = 4, cols = COLS;
    element **lists = sparse_matrix_to_lists(A, rows, cols);
    for (int i = 0; i < rows; i++) {
        printf("Row %d:", i);
        for (element *cur = lists[i]; cur != NULL; cur = cur->next) {
            printf(" (%d at col %d)", cur->data, cur->col);
        }
        printf("\n");
    }
    for (int i = 0; i < rows; i++) {
        free(lists[i]);
    }
    free(lists);
    return 0;
}

element **sparse_matrix_to_lists(int A[][COLS], int rows, int cols) {

    element** lists = (element**)calloc(rows, sizeof(element*));
    element* newNode = NULL;
    for (int row = 0; row < rows; row++) {
        for (int col = cols - 1; col >= 0; col--) {
            if (A[row][col] != 0) {
                newNode = (element*)calloc(1, sizeof(element));
                newNode->data = A[row][col];
                newNode->col = col;
                newNode->next = lists[row];
                lists[row] = newNode;
            }
        }
    }
    return lists;
}
*/

/*ex2

//Function prototypes for exercise 2
int is_prime(int num);
int primes_interval(int a, int b, int **primes);

int main() {
    int a, b;
    int *primes = NULL;
    int count;

    printf("please input the first number:\n");
    scanf("%d", &a);
    printf("please input the second number:\n");
    scanf("%d", &b);
    printf("\n");

    //Call the function to fill the primes array
    count = primes_interval(a, b, &primes);

    // Print results
    if (count > 0) {
        printf("Primes in [%d, %d]:", a, b);
        for (int i = 0; i < count; i++) {
            printf(" %d", primes[i]);
        }
        printf("\n");
        printf("there is %d numbers in count", count);
        free(primes);
    } else {
        printf("No primes found in [%d, %d]\n", a, b);
    }

    return 0;
}

int is_prime(int num) {

    if (num <= 1) {
        return 0;
    }
    if (num == 2) {
        return 1;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

int primes_interval(int a, int b, int **primes) {

    int* arr = (int*)malloc((b + 1) * sizeof(int));
    int count = 0;
    for (int i = a; i <= b; i++) {
        if (is_prime(i) == 1) {
            arr[count] = i;
            count++;
        }
    }
    *primes = (int*)realloc(arr, sizeof(int) * (count + 1));
    return count;
} */


/*ex3

void transform_file_to_file (char* infile, char* outfile);
int convert_to_str (char ch, char* str);

int main () {

    transform_file_to_file("Files/3infile.txt", "Files/3outfile.txt");
    return 0;

}

void transform_file_to_file (char* infile, char* outfile) {

    FILE* in = fopen(infile, "r");
    if (in == NULL) {
        exit(1);
    }
    FILE* out = fopen(outfile, "w");
    if (out == NULL) {
        fclose(in);
        exit(1);
    }
    char ch;
    char* str = (char*)calloc(17,sizeof(char)); // 16 + '\0'
    while (fscanf(in, "%c" , &ch) == 1) {
        if (convert_to_str(ch, str) == 1) {
            fprintf(out, "%s", str);
        }
        str[0] = '\0';
    }
    fclose(in);
    fclose(out);
}

int convert_to_str (char ch, char* str) {

    char low_hexa [15] = {'1', '2', '3', '4', '5', '6', '7', '8', '9','a', 'b', 'c', 'd', 'e', 'f'};
    char high_hexa [15] = {'1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C', 'D', 'E', 'F'};
    char numbers [9] = {'1','2','3','4','5','6','7','8','9'};

    if (ch >= '1' && ch <= '9') {
        int counter = ch - '0'; // '3' - '0'
        for (int i = 0; i < counter; i++) {
            str[i] = numbers[i];
        }
        str[counter] = '\0';
        return 1;
    }
    else if (ch >= 'a' && ch <= 'z') {
        if (ch >= 'a' && ch <= 'f') {
            int counter = ch - 'a' + 9;
            for (int i = 0; i < counter + 1; i++) {
                str[i] = low_hexa[i];
            }
            str[counter + 1] = '\0';
            return 1;
        }
        else {
            str[0] = toupper(ch);
            str[1] = '\0';
            return 1;
        }
    }
    else if (ch >= 'A' && ch <= 'Z') {
        if (ch >= 'A' && ch <= 'F') {
            int counter = ch - 'A' + 9;
            for (int i = 0; i < counter + 1; i++) {
                str[i] = high_hexa[i];
            }
            str[counter + 1] = '\0';
            return 1;
        }
        else {
            str[0] = tolower(ch);
            str[1] = '\0';
            return 1;
        }
    }
    else {
        return 0;
    }
}*/

/*ex3 alternative

int main () {

    FILE* infile = fopen("Files/3infile.txt", "r");
    FILE* outfile = fopen("Files/3outfile.txt", "w");
    if (!infile) {
        exit(1);
    }
    if (!outfile) {
        fclose(infile);
        exit(1);
    }

    // while file not finished
    // if g - z
    //if G - Z
    // numbers
    // if hexa

    char ch;
    while (fscanf(infile, "%c", &ch) != EOF) {
        if (ch >= 'g' && ch <= 'z') {
            fprintf(outfile, "%c", toupper(ch));
        }
        else if (ch >= 'G' && ch <= 'Z') {
            fprintf(outfile, "%c", tolower(ch));
        }
        else if (isdigit(ch)) {
            char curr;
            for (curr = '1'; curr <= ch; curr++) {
                fprintf(outfile, "%c", curr);
            }
        }
        else if (isalpha(ch)) {
            fprintf(outfile, "%s", "123456789");
            char curr = isupper(ch) ? 'A' : 'a';
            for (; curr <= ch; curr++) {
                fprintf(outfile, "%c", curr);
            }
        }
    }
    fclose(infile);
    fclose(outfile);

    return 0;
}*/



/*ex4*/

// אין לי כוח


/*ex5*/
// סעיף א׳

// 3 | 5 ---> 0011 | 0101
// 0011
// ||||
// 0101
// ====
// 0111 ---> 7


// סעיף ב׳

// char str1[] = "hello", *str2 = "hello";
// if (str1 == str1) printf("yes");


/*ex6*/
