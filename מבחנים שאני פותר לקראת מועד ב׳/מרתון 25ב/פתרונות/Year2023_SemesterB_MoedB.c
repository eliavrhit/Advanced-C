#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node {
	int value;
	struct node* next;
} node;

typedef struct {
	char film_code[10];
	int copies;
	int year;
} film;

typedef struct filmNode {
	film data;
	struct filmNode* next;
} filmNode;

node* ex1(node* lst, int m) {
    node* head = NULL, *last = NULL, *movingNode = NULL;
    int i;
    while (lst != NULL) {
        for (i = 0; i < m - 2; i++) {
            lst = lst->next;
        }
        movingNode = lst->next;
        lst->next = movingNode->next;
        movingNode->next = NULL;
        if (head == NULL) {
            head = movingNode;
            last = head;
        } else {
            last->next = movingNode;
            last = last->next;
        }
        lst = lst->next;
    }
    return head;
}

filmNode* ex2Lists(char* fileName, int copies_limit, int last_year, int* size) {
    FILE* fin = fopen(fileName, "rb");
    *size = 0;
    if (!fin) {
        return NULL;
    }
    filmNode* head = (filmNode*)malloc(sizeof(filmNode)); //dummy
    filmNode* last = head;
    film singleFilm;
    while(fread(&singleFilm, sizeof(film), 1, fin)) {
        if (singleFilm.copies <= copies_limit && singleFilm.year <= last_year) {
            last->next = (filmNode*)malloc(sizeof(filmNode));
            last = last->next;
            last->data = singleFilm;
            (*size)++;
        }
    }
    last->next = NULL;
    //delete dummy
    last = head;
    head = head->next;
    free(last);
    last = NULL;
    fclose(fin);
    return head;
}

char* ex3(char* sentence, char* separators) {
    static char* start;
    if (sentence != NULL) {
        start = sentence;
    }
    char* word = (char*)malloc((strlen(start) + 1) * sizeof(char));
    int i;
    for(; *start != '\0' && strchr(separators, *start); start++);
    for(i = 0; *start != '\0' && !strchr(separators, *start); start++, i++) {
        word[i] = *start;
    }
    if (i == 0) { // there is no word to copy
        free(word);
        return NULL;
    }
    word[i] = '\0';
    word = (char*)realloc(word, (i + 1) * sizeof(char));
    return word;
}

int myStrchr(char* separators, char ch) {
	int i;
	for (i = 0; separators[i] != '\0'; i++) {
		if (separators[i] == ch) {
			return 1;
		}
	}
	return 0;
}