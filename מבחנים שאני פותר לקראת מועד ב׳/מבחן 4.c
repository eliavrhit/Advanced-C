#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

/*ex1

// הגדרת המבנה של איבר ברשימה
typedef struct Item {
    int data;
    struct Item *next;
    struct Item *skip;
} item;

// הצהרת הפונקציה שנדרשת בסעיף א׳
void updateSkipPointers(item *head);
item* insertFirst(item *head, int data);

int main() {
    // יצירת איברים לדוגמה
    item a = {123, NULL, NULL};
    item b = {40, NULL, NULL};
    item c = {4, NULL, NULL};
    item d = {54, NULL, NULL};
    item e = {554, NULL, NULL};
    item f = {32, NULL, NULL};
    item g = {10, NULL, NULL};
    item h = {777, NULL, NULL};

    // חיבור איברים לפי next
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = &e;
    e.next = &f;
    f.next = &g;
    g.next = &h;
    h.next = NULL;

    // קריאה לפונקציה שמעדכנת את מצביעי ה-skip
    updateSkipPointers(&a);

    // הכנסת איבר חדש לתחילת הרשימה
    item *new_head = insertFirst(&a, 999);

    free(new_head);

    return 0;
}

void updateSkipPointers(item *head) {

    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        head->skip = NULL;
        return;
    }
    item* step = head, *double_step = head->next;
    while (double_step != NULL) {
        step->skip = double_step;
        step = step->next;
        if (double_step->next == NULL) {
            break;
        }
        double_step = double_step->next->next;
    }
    while (step != NULL) {
        step->skip = NULL;
        step = step->next;
    }
}

item* insertFirst(item *head, int data) {

    item *new_item = malloc(sizeof(item));
    new_item->data = data;
    new_item->next = head;
    head = new_item;
    updateSkipPointers(head);
    return head;
}*/


/*ex2*/

int countCharsAndWords(char* file_name, int* words);
int flipFile(char* file_name);


int main() {

    int words;
    printf("number of chars: %d\nnumber of words: %d\n", countCharsAndWords("Files/4input.txt", &words), words);

    flipFile("Files/4swap.txt");

    return 0;
}

int countCharsAndWords(char* file_name, int* words) {

    FILE* in = fopen(file_name, "r");
    *words = 0;
    if (!in) {
        return 0;
    }
    char ch, prev = '5';
    int count = 0;
    while (fscanf(in, "%c", &ch) != EOF) {
        if (isalpha(ch)) {
            if (prev == ' ' || prev == '\n') {
                (*words)++;
                count++;
            }
            else {
                count++;
            }
        }
        else if (ch == ' ') {
            count++;
        }
        else if (ch == '\n') {
            count++;
        }
        prev = ch;
    }
    count++;
    (*words)++;
    fclose(in);
    return count;
}

int flipFile(char* file_name) {

    // החלפה
    FILE* swap = fopen(file_name, "r+");
    if (!swap) {
        return 0;
    }
    int words;
    int left = 0, right;
    char leftCh, rightCh;
    right = countCharsAndWords(file_name, &words);
    if (right == 0) {
        fclose(swap);
        return 0;
    }int count = right;
    right--;
    // swap(&left, &right);
    while (left < right) {
        // read left char
        fseek(swap, left, SEEK_SET);
        leftCh = fgetc(swap);
        //read right char
        fseek(swap, right, SEEK_SET);
        rightCh = fgetc(swap);
        // write right in left
        fseek(swap, left, SEEK_SET);
        fputc(rightCh, swap);
        //write left in right
        fseek(swap, right, SEEK_SET);
        fputc(leftCh, swap);

        left++;
        right--;
    }

    fclose(swap);
    return words;
}