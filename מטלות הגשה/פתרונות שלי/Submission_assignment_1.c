/*
Assigned by:
    Student1_Eliav Refaely #206646929
*/

#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* Constant definitions */

#define N 3
#define ROWS 4
#define COLS 5

/* Type definitions */

typedef struct number {
    unsigned long long num;
    int sum;
} Number;

typedef struct triad {
    int i, j, value;
} Triad;

typedef struct item {
    Triad data;
    struct item* next;
} Item;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);

/* Declarations of auxiliary functions */

int isPrime(int num);
int digitSum(unsigned long long num);
int neighborMax(int A[][COLS], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);
Triad createThree(int i, int j, int value);
void insert(Item** pHead, Triad data);
void printArray(Number* arr, int size);
void inputMatrix(int A[][COLS], int rows, int cols);
void printMatrix(int A[][COLS], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void inputDynamicMatrix(int** A, int rows, int cols);
void freeMatrix(void** A, int rows);
void printList(Item* lst);
void freeList(Item* lst);

// פונקציית main: מציגה תפריט ומריצה את אחד משלושת התרגילים לפי בחירת המשתמש
int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do {
            for (i = 1; i <= N; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select) {
            case 1: Ex1(); break;
            case 2: Ex2(); break;
            case 3: Ex3(); break;
            }
        } while (all_Ex_in_loop && select);
    return 0;
}

// ----------------- Exercise 1 -----------------
// Ex1: קולט שני מספרים, מחשב אילו מהם סכום ספרותיהם ראשוני, ומדפיס
void Ex1()
{
    unsigned long long n1, n2;
    int size = 0;
    Number* arr;

    printf("Enter n1 and n2 (n1 < n2): ");
    scanf("%llu%llu", &n1, &n2);

    arr = primeSums(n1, n2, &size);

    if (arr)
    {
        printArray(arr, size);
        printf("Total count: %d\n", size);
        free(arr);
    }
    else
    {
        printf("No matching numbers found.\n");
    }
}

// primeSums: יוצרת מערך דינמי של מספרים שסכום ספרותיהם ראשוני בטווח [n1, n2]
Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
    int capacity = 2;
    int count = 0;
    Number* result = (Number*)malloc(capacity * sizeof(Number));
    if (!result) return NULL;

    for (unsigned long long num = n1; num <= n2; num++)
    {
        int sum = digitSum(num);
        if (isPrime(sum))
        {
            if (count == capacity)
            {
                capacity *= 2;
                Number* temp = (Number*)realloc(result, capacity * sizeof(Number));
                if (!temp)
                {
                    free(result);
                    return NULL;
                }
                result = temp;
            }
            result[count].num = num;
            result[count].sum = sum;
            count++;
        }
    }

    if (count == 0)
    {
        free(result);
        *p_size = 0;
        return NULL;
    }

    *p_size = count;
    return result;
}

// digitSum: מחשבת את סכום הספרות של מספר
int digitSum(unsigned long long num)
{
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// isPrime: בודקת האם מספר הוא ראשוני
int isPrime(int num)
{
    if (num < 2) return 0;
    if (num == 2) return 1;
    if (num % 2 == 0) return 0;
    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

// printArray: מדפיסה מערך מסוג Number בגודל נתון
void printArray(Number* arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("num: %llu, sum: %d\n", arr[i].num, arr[i].sum);
}

// ----------------- Exercise 2 -----------------
// Ex2: קולט מטריצה, בונה מטריצה חדשה עם מקסימום שכנים, ומדפיס
void Ex2()
{
    int A[ROWS][COLS];
    int** B;

    inputMatrix(A, ROWS, COLS);
    printf("Original matrix:\n");
    printMatrix(A, ROWS, COLS);

    B = matrixMaxNeighbor(A, ROWS, COLS);
    printf("Matrix of max neighbors:\n");
    printDynamicMatrix(B, ROWS, COLS);

    freeMatrix((void**)B, ROWS);
}

// matrixMaxNeighbor: בונה מטריצה שבה כל תא הוא המקסימום מבין שכניו הישירים
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols)
{
    int** B = allocMatrix(rows, cols);
    if (!B) return NULL;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            B[i][j] = neighborMax(A, rows, cols, i, j);

    return B;
}

// neighborMax: מחזירה את המקסימום מבין שכניו הישירים של תא
int neighborMax(int A[][COLS], int rows, int cols, int i, int j)
{
    int max = INT_MIN;

    if (i > 0 && A[i - 1][j] > max) max = A[i - 1][j];
    if (i < rows - 1 && A[i + 1][j] > max) max = A[i + 1][j];
    if (j > 0 && A[i][j - 1] > max) max = A[i][j - 1];
    if (j < cols - 1 && A[i][j + 1] > max) max = A[i][j + 1];

    return max;
}

// inputMatrix: קורא ערכי מטריצה מהמשתמש
void inputMatrix(int A[][COLS], int rows, int cols)
{
    printf("Enter matrix values (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &A[i][j]);
}

// printMatrix: מדפיס מטריצה סטטית
void printMatrix(int A[][COLS], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
}

// allocMatrix: מקצה זיכרון עבור מטריצה דינמית
int** allocMatrix(int rows, int cols)
{
    int** mat = (int**)malloc(rows * sizeof(int*));
    if (!mat) return NULL;
    for (int i = 0; i < rows; i++)
    {
        mat[i] = (int*)malloc(cols * sizeof(int));
        if (!mat[i])
        {
            for (int j = 0; j < i; j++)
                free(mat[j]);
            free(mat);
            return NULL;
        }
    }
    return mat;
}

// printDynamicMatrix: מדפיסה מטריצה דינמית
void printDynamicMatrix(int** A, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("%4d", A[i][j]);
        printf("\n");
    }
}

// freeMatrix: משחררת זיכרון של מטריצה דינמית
void freeMatrix(void** A, int rows)
{
    for (int i = 0; i < rows; i++)
        free(A[i]);
    free(A);
}

// ----------------- Exercise 3 -----------------
// Ex3: קולט מטריצה דינמית ויוצר ממנה שתי רשימות מקושרות לפי תנאים מתמטיים
void Ex3()
{
    int rows, cols;
    int** A;
    Item* L1 = NULL;
    Item* L2 = NULL;

    printf("Enter number of rows and cols: ");
    scanf("%d%d", &rows, &cols);

    A = allocMatrix(rows, cols);
    inputDynamicMatrix(A, rows, cols);
    printf("Input matrix:\n");
    printDynamicMatrix(A, rows, cols);

    createThreeLists(A, rows, cols, &L1, &L2);

    printf("L1:\n");
    printList(L1);
    printf("L2:\n");
    printList(L2);

    freeMatrix((void**)A, rows);
    freeList(L1);
    freeList(L2);
}

// inputDynamicMatrix: קורא ערכי מטריצה דינמית מהמשתמש
void inputDynamicMatrix(int** A, int rows, int cols)
{
    printf("Enter matrix values (%d x %d):\n", rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            scanf("%d", &A[i][j]);
}

// createThreeLists: בונה את הרשימות L1 ו־L2 לפי התנאים על i, j ו־value
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2)
{
    *pL1 = NULL;
    *pL2 = NULL;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            int value = A[i][j];
            Triad t = createThree(i, j, value);
            if (i + j == value)
                insert(pL1, t);
            if (2 * j == i + value)
                insert(pL2, t);
        }
}

// createThree: בונה טיפוס Triad עם ערכי i, j ו־value
Triad createThree(int i, int j, int value)
{
    Triad t;
    t.i = i;
    t.j = j;
    t.value = value;
    return t;
}

// insert: מוסיף איבר חדש לראש רשימה מקושרת
void insert(Item** pHead, Triad data)
{
    Item* newItem = (Item*)malloc(sizeof(Item));
    if (!newItem) return;
    newItem->data = data;
    newItem->next = *pHead;
    *pHead = newItem;
}

// printList: מדפיס רשימה מקושרת של Triad
void printList(Item* lst)
{
    while (lst)
    {
        printf("(%d, %d, %d) -> ", lst->data.i, lst->data.j, lst->data.value);
        lst = lst->next;
    }
    printf("NULL\n");
}

// freeList: משחרר את כל האיברים ברשימה מקושרת
void freeList(Item* lst)
{
    while (lst)
    {
        Item* tmp = lst;
        lst = lst->next;
        free(tmp);
    }
}