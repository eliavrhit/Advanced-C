#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// ex1a
typedef struct VectorItem
{
    int data;
    struct VercorItem *next;
} VectorItem;

VectorItem *ex1b()
{
    int n, i;
    VectorItem *head = NULL, *newNode = NULL, *last = NULL;
    printf("Please enter length of the vector: ");
    scanf("%d", &n);
    printf("Please enter elements of the vercor:\n");
    for (i = 0; i < n; i++)
    {
        newNode = (VectorItem *)malloc(sizeof(VectorItem));
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
    }
    return head;
}

VectorItem *ex1c(VectorItem *a, VectorItem *b)
{
    int dataA, dataB;
    VectorItem *c = NULL, *last = NULL, *newNode = NULL;

    while (a != NULL || b != NULL)
    {
        dataA = 0;
        if (a != NULL)
        {
            dataA = a->data;
            a = a->next;
        }
        dataB = 0;
        if (b != NULL)
        {
            dataB = b->data;
            b = b->next;
        }
        newNode = (VectorItem *)malloc(sizeof(VectorItem));
        newNode->data = dataA * dataB;
        newNode->next = NULL;
        if (c == NULL)
        {
            c = newNode;
        }
        else
        {
            last->next = newNode;
        }
        last = newNode;
    }
    return c;
}

int ex2(char **mat, int rows, int columns, char **mask, int maskRows, int maskColumns)
{
    int rowMat, colMat, rowMask, colMask, equals, zeros;
    for (rowMat = 0; rowMat <= rows - maskRows; rowMat++)
    {
        for (colMat = 0; colMat <= columns - maskColumns; colMat++)
        {
            equals = 0;
            zeros = 0;
            for (rowMask = 0; rowMask < maskRows; rowMask++)
            {
                for (colMask = 0; colMask < maskColumns; colMask++)
                {
                    if (mask[rowMask][colMask] != 0)
                    {
                        if (mat[rowMat + rowMask][colMat + colMask] == mask[rowMask][colMask])
                        {
                            equals++;
                        }
                    }
                    else
                    {
                        zeros++;
                    }
                }
            }
            if (equals > 0 && equals == maskRows * maskColumns - zeros)
            {
                return 1;
            }
        }
    }
    return 0;
}