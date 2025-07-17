#include <stdio.h>
#include <string.h>

int lastIndexOf(char *str, char ch) {
    int lastIndex = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ch)
            lastIndex = i;
    }
    return lastIndex;
}
// מחזירה את מיקום ההופעה האחרונה של תו במחרוזת, או -1 אם אינו קיים.

void swapStrings(char *str1, char *str2) {
    char temp[1000]; // Buffer זמני (אפשר גם dynamic allocation)
    strcpy(temp, str1);
    strcpy(str1, str2);
    strcpy(str2, temp);
}
// מחליפה בין התוכן של שתי מחרוזות.

void processString(char *str) {
    char result[1000];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'f') {
            j += sprintf(result + j, "%d", ch - 'a');
        } else if (ch >= 'A' && ch <= 'F') {
            j += sprintf(result + j, "%d", ch - 'A');
        } else if (ch >= '0' && ch <= '9') {
            result[j++] = ch;
        }
        // שאר התווים לא מועתקים
    }
    result[j] = '\0';
    strcpy(str, result);
}
// משנה מחרוזת לפי כללים: אותיות a-f/A-F למספרים, ספרות נשארות, כל השאר נמחק.

int main() {
    // שאלה 1
    char str1[] = "abcadeaxy";
    printf("Last index of 'a': %d\n", lastIndexOf(str1, 'a')); // צ"ל 6

    // שאלה 2
    char s1[100] = "Hello!";
    char s2[100] = "abc";
    swapStrings(s1, s2);
    printf("After swap:\ns1: %s\ns2: %s\n", s1, s2);

    // שאלה 3
    char s3[100] = "aF19Bc";
    processString(s3);
    printf("Processed string: %s\n", s3); // צ"ל 01519112

    return 0;
}