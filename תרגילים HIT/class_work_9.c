#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*ex1
int reverseString(char* str);
int isPalindrome(char* str);

int main() {

    int n = 100;
    char* str = (char*)malloc(n * sizeof(char));
    if (!str) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    puts("please input a string:");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    puts("this is the string:");
    puts(str);
    reverseString(str);
    free(str);
    return 0;
}

int reverseString(char* str) {

    char* end = str;
    char* start = str;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
    puts("this is the reversed string:");
    puts(str);
    return isPalindrome(str) == 1 ? 1 : 0;
}

int isPalindrome(char* str) {

    char* left = str;
    char* right = str;
    while (*right != '\0') {
        right++;
    }
    right--;
    int isPalindrome = 1;
    while (left < right) {
        if (*left != *right) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }
    if (isPalindrome == 1)
        puts("this is a Palindrome");
    else
        puts("this is not a Palindrome");
    return isPalindrome;
}
*/

/*ex2
void scanString(char* str, int* smallDigits, int* bigDigits, int* number, int* signs);

int main() {

    int n = 100;
    int smallDigits = 0, bigDigits = 0, number = 0, signs = 0;
    char* str = (char*)malloc(n * sizeof(char));
    if (!str) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    puts("please input a string:");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    puts("this is the string:");
    puts(str);
    scanString(str, &smallDigits, &bigDigits, &number, &signs);
    puts("smallDigits:");
    printf("%d\n", smallDigits);
    puts("bigDigits:");
    printf("%d\n", bigDigits);
    puts("number:");
    printf("%d\n", number);
    puts("signs:");
    printf("%d\n", signs);
    free(str);
    return 0;

}

void scanString(char* str, int* smallDigits, int* bigDigits, int* number, int* signs) {

    char* start = str;
    while (*start != '\0') {
        if (*start >= 'a' && *start <= 'z') {
            (*smallDigits)++;
        }
        else if (*start >= 'A' && *start <= 'Z') {
            (*bigDigits)++;
        }
        else if (*start >= '0' && *start <= '9') {
            (*number)++;
        }
        else {
            (*signs)++;
        }
        start++;
    }
}
*/

/*ex3

void removeSpaces(char* str);

int main() {

    int n = 100;
    char* str = malloc(n * sizeof(char));
    if (!str) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    puts("please input a string:");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';
    puts("this is the string:");
    puts(str);
    removeSpaces(str);
    puts("this is the new string:");
    printf("%s\n", str);
    free(str);
    return 0;
}

void removeSpaces(char* str) {

    char* read = str;
    char* write = str;
    int spaceEncountered = 0;
    while (*read != '\0') {
        if (*read != ' ') {
            *write = *read;
            write++;
            spaceEncountered = 0;
        } else {
            if (!spaceEncountered) {
                *write = ' ';
                write++;
                spaceEncountered = 1;
            }
        }
        read++;
    }
    *write = '\0';
}
*/