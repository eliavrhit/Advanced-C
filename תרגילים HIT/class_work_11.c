#include <stdio.h>
int countLines (char* filename);
void letterFrequency (char* filename, int counts[]);
void removeSpaces (char* infile, char* outfile);

int main() {

    int numLines = 0;
    numLines=countLines("input.txt");
    printf("The number of lines is %d", numLines);

    int counts[26] = {0};
    letterFrequency("input.txt", counts);

    char* infile = "infile.txt";
    char* outfile = "outfile.txt";
    removeSpaces(infile, outfile);

    return 0;
}

int countLines (char* filename) {

    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }
    char c;
    int numLines = 0;
    while (fscanf(file, "%c", &c) == 1) {
        if (c == '\n') {
            numLines++;
        }
    }
    fclose(file);
    return numLines;
}

void letterFrequency (char* filename, int counts[])
{
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("File does not exist");
        return;
    }
    for (int i = 0; i < 26; i++) {
        counts[i] = 0;
    }
    int pos = 0;
    char c;
    while (fscanf(file, "%c", &c) == 1) {
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
            pos = c - 'A';
            counts[pos]++;
        }
    }
    for (int i = 0; i < 26; i++) {
        printf("The letter %c is appearing %d times.\n", i + 'A', counts[i]);
    }
    fclose(file);
}

void removeSpaces (char* infile, char* outfile)
{
    FILE* in = fopen(infile, "r");
    if (in == NULL) {
        printf("inFile does not exist");
        return;
    }
    FILE* out = fopen(outfile, "w");
    if (out == NULL) {
        printf("outFile does not exist");
        return;
    }
    char c, w;
    while (fscanf(in, "%c", &c) == 1) {
        if (c != ' ') {
            fprintf(out, "%c", c);
        }
    }
    fclose(in);
    fclose(out);

}