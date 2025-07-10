
#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Constant definitions */

#define N 3

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

char** split(char letter, char* str, int* p_size);
void createFile(char* filename);
char commonestLetter(char* filename);
void decode(char* text);

/* Declarations of auxiliary functions */

void printStringsArray(char** str_arr, int size);
void freeMatrix(void** A, int rows);

/* ------------------------------- */

int main()
{
    int select = 0, i, all_Ex_in_loop = 0;
    printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
    if (scanf("%d", &all_Ex_in_loop) == 1)
        do
        {
            for (i = 1; i <= N; i++)
                printf("Ex%d--->%d\n", i, i);
            printf("EXIT-->0\n");
            do {
                select = 0;
                printf("please select 0-%d : ", N);
                scanf("%d", &select);
            } while ((select < 0) || (select > N));
            switch (select)
            {
            case 1: Ex1(); break;
            case 2: Ex2(); break;
            case 3: Ex3(); break;
            }
        } while (all_Ex_in_loop && select);
        return 0;
}


/* Function definitions */

void Ex1()
{
    /* Called functions:
        split, printStringsArray, freeMatrix */

    char str[100], letter;
    int p_size;
    char** wordArray;

    // Get user input for string and letter
    printf("please enter string up to 99 charactars: \n");
    getchar();// Clear the buffer
    fgets(str, 100, stdin);
    printf("please enter charactar: ");
    letter = getchar();
    getchar();// Clear the buffer

    // Split the string based on the letter
    wordArray = split(letter, str, &p_size);

    // Print the resulting array of words
    printStringsArray(wordArray, p_size);

    // Free the allocated memory
    freeMatrix((void**)wordArray, p_size);

}

void Ex2()
{
    char str[] = "input.txt", c;
    createFile(str);// Create the file and write user input to it
    c = commonestLetter(str); // Find the most common letter in the file
    printf("\nThe letter that appear the most is: %c\n", c);// Print the most common letter
}

void Ex3()
{

        char str[] = "Btwlzx Dqqes Eq|pj2 Tjhvqujs Iqoqjy bpg Eqfxtx Xcwwtt";
        printf("before decode:\n");
        printf("%s\n", str);// Print the decoded string
        printf("after decode:\n");
        decode(str);// Decode the string
        printf("%s\n", str);// Print the decoded string
}

char** split(char letter, char* str, int* p_size)
{

    int new_wordLen = 0, str_len = strlen(str), i, j, k = 0, start, totalWords = 0;
    str[str_len - 1] = '\0';
    str_len--;

    // Count the number of words to allocate memory
    for(i = 0; i < str_len; i++) {
        if (str[i] == letter || str[i] == letter - 32) {
            if (i == 0) {
                totalWords++;
            }
            else if(str[i-1] == ' ') {
                totalWords++;
            }
        }
    }

    // Allocate memory for the array of words
    char** wordArray = (char**)malloc(totalWords * sizeof(char*));
    if (wordArray == NULL)
        return NULL;

    // Extract words starting with the given letter
    for (i = 0; i < str_len; i++) {
        if (str[i] == letter || str[i] == letter - 32) {
            if (i == 0 || str[i - 1] == ' ') {
                for (j = i; str[j] != ' ' && str[j] != 0; j++) {
                    new_wordLen++;
                }
                wordArray[k] = (char*)malloc(new_wordLen + 1); // Allocate
                j = 0;

                for (i; str[i] != ' ' && str[i] != 0; i++, j++) {
                    wordArray[k][j] = str[i]; // Copy the word
                }
                wordArray[k][j] = '\0';  // Null-terminate the word
                k++;
            }

        }
        new_wordLen = 0;

    }
    if (!k) return NULL;

    *p_size = k;  // Set the size of the resulting array
    return wordArray;
}

/* Function to create a file and write user input to it */
void createFile(char* filename)
{
    char c;
    FILE* fl = fopen(filename, "w");
    if (fl == NULL)
    {
        printf("File not found!\n");
        return;
    }
    printf("Please enter the file data:\n");
    printf("**In order to finish the data typing press: Enter -> ctrl-z -> Enter** \n");
    getchar();
    while ((c =getchar()) != EOF) {  // Read input until EOF
        fputc(c, fl);  // Write character to file
    }
    fclose(fl);
}


char commonestLetter(char* filename)
{
    FILE* fl = fopen(filename, "r");
    if (fl == NULL)
    {
        printf("File not found!\n");
        return '\0';
    }
    int arr[26] = { 0 }, max_count = 0;
    char c = 0;
    int i;
    while ((c = fgetc(fl)) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            arr[c - 'a']++; // Increment count for lowercase letter
        }
        if (c >= 'A' && c <= 'Z')
        {
            arr[c - 'A']++; // Increment count for uppercase letter
        }


    }
    rewind(fl);
    c = fgetc(fl);
    max_count = arr[0];
    for (i = 1; i < 26; i++)
    {
        if (arr[i] >= max_count)
        {
            max_count = arr[i];
            c = i + 'a';
        }
    }
    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        c = '\0';
    fclose(fl);
    return c - 32;
}


/* Decodes a string by shifting characters backwards */
void decode(char* text)
{
    int i, ascii_counter = 1;

    for(i = 0; text[i] != '\0' ; i++, ascii_counter++){
        if(text[i] != ' ') {
            text[i] -= ascii_counter; // Shift character
        }
        else {
            ascii_counter = 0; // Reset counter at space
        }
    }
}

/* Definitions of auxiliary functions */

/* Auxiliary function: Prints an array of strings */
void printStringsArray(char** str_arr, int size) {
    int i;
    printf("the words are:\n");
    for (i = 0; i < size; i++) {
        printf("word number %d: %s\n", i + 1, str_arr[i]); // Print each string
    }
}

/* Auxiliary function: Frees a matrix of allocated memory */
void freeMatrix(void** A, int rows) {
    int i;
    for (i = 0; i < rows; i++) {
        free(A[i]);  // Free each row
    }
    if(rows != 1)
        free(A); // Free the array of pointers if there are multiple rows
}


