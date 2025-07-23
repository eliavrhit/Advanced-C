#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Item
{
    int data;
    struct Item *next;
    struct Item *skip;
} Item;

typedef struct line
{
    int x1; // First end point
    int y1;
    int x2; // Second end point
    int y2;
} Line;

typedef enum
{
    White,
    Black
} Color;

typedef struct picture
{
    int rows; // rows - Dimensions of the picture
    int cols; // cols - Dimensions of the picture

    Color **color; // Two-dimensional dynamic array of pixel colors [rows][cols]
} Picture;

void ex1a(Item *head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        head->skip = NULL;
        return;
    }
    Item *step = head, *doubleStep = head->next;
    while (doubleStep != NULL)
    {
        step->skip = doubleStep;
        step = step->next;
        if (doubleStep->next == NULL)
        {
            break;
        }
        doubleStep = doubleStep->next->next;
    }
    while (step != NULL)
    {
        step->skip = NULL;
        step = step->next;
    }
}

Item *ex1b(Item *head, int data)
{
    Item *newHead = (Item *)malloc(sizeof(Item));
    newHead->data = data;
    newHead->next = head;
    head = newHead;
    ex1a(head);
    return head;
}

int ex2a(char *file_name, int *words)
{
    FILE *fin = fopen(file_name, "r");
    *words = 0;
    if (!fin)
    {
        return 0;
    }
    int count = 0;
    char curr, prev = ' ';
    while ((curr = fgetc(fin)) != EOF)
    {
        count++;
        if ((curr == ' ' || curr == '\n') && prev != ' ')
        {
            (*words)++;
        }
        prev = curr;
    }
    fclose(fin);
    return count;
}

int ex2b(char *file_name)
{
    FILE *f = fopen(file_name, "r+");
    if (!f)
    {
        return 0;
    }
    int left = 0, right, words;
    char leftCh, rightCh;
    right = ex2a(file_name, &words);
    if (right == 0)
    {
        fclose(f);
        return 0;
    }
    right--;
    while (left < right)
    {
        // read left char
        fseek(f, left, SEEK_SET);
        leftCh = fgetc(f);
        // read right char
        fseek(f, right, SEEK_SET);
        rightCh = fgetc(f);
        // write right char into left
        fseek(f, left, SEEK_SET);
        fputc(rightCh, f);
        // write left char into right
        fseek(f, right, SEEK_SET);
        fputc(leftCh, f);

        left++;
        right--;
    }

    fclose(f);
    return words;
}

void ex3a(Picture *picture, int rows, int cols)
{
    picture->rows = rows;
    picture->cols = cols;
    picture->color = (Color **)calloc(rows, sizeof(Color *));
    int row;
    for (row = 0; row < rows; row++)
    {
        picture->color[row] = (Color *)calloc(cols, sizeof(Color));
    }
}

int ex3b(Picture *picture, Line *line)
{
    int row, col;
    for (row = line->x1; row <= line->x2; row++)
    {
        for (col = line->y1; col <= line->y2; col++)
        {
            if (isBlack(picture, row, col) ||
                isBlack(picture, row - 1, col) || // up
                isBlack(picture, row + 1, col) || // down
                isBlack(picture, row, col - 1) || // left
                isBlack(picture, row, col + 1))
            { // right
                return 0;
            }
        }
    }
    for (row = line->x1; row <= line->x2; row++)
    {
        for (col = line->y1; col <= line->y2; col++)
        {
            picture->color[row][col] = Black;
        }
    }
    return 1;
}

int isBlack(Picture *picture, int row, int col)
{
    return (row >= 0 && row < picture->rows && col >= 0 && col < picture->cols &&
            picture->color[row][col] == Black);
}