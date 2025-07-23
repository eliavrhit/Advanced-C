#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct pair 
{
  int num_text_rows;
  int num_bin_records;
} Pair;

Pair* ex3(char**InFiles, int n) {
    Pair* results = (Pair*)malloc(n * sizeof(Pair));
    int i, sizeOfRecord;
    for (i = 0; i < n; i++) {
        if (tolower(InFiles[i][0]) == 'b') {
            sizeOfRecord = getSizeOfRecord(InFiles[i]);
            results[i].num_text_rows = -1;
            results[i].num_bin_records = countRecords(InFiles[i], sizeOfRecord);
        } else {
            results[i].num_bin_records = -1;
            results[i].num_text_rows = countRows(InFiles[i]);
        }
    }
    return results;
}

int getSizeOfRecord(char* fileName) {
    int i, sizeOfRecord = 0, tens = 1;
    for (i = 0; fileName[i] != '.'; i++);
    i--;
    while(isdigit(fileName[i])) {
        sizeOfRecord += (fileName[i] - '0') * tens;
        tens *= 10;
        i--;
    }
    return sizeOfRecord;
}

int countRecords(char* fileName, int sizeOfRecord) {
    FILE* fin = fopen(fileName, "rb");
    if (!fin) {
        return 0;
    }
    int count = 0;
    char ch;
    // fseek(fin, 0, SEEK_END);
    // count = ftell(fin);
    while (fread(&ch, 1, 1, fin)) {
        count++;
    }
    fclose(fin);
    return count / sizeOfRecord;
}

int countRows(char* fileName) {
    FILE* fin = fopen(fileName, "r");
    if (!fin) {
        return 0;
    }
    int count = 0;
    char ch;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }
    fclose(fin);
    return count;
}