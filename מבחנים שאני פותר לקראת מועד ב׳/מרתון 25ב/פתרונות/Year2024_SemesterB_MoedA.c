#include <stdio.h>
#include <stdlib.h>

typedef struct item
{
    int digit;
    struct item *next;
} Item;

typedef struct
{
    int size;
    int *ptr;
} dyn_array;

int ex1(Item *L1, Item *L2)
{
    Item *ptr1 = L1, *ptr2 = L2;
    while (ptr1 != NULL && ptr2 != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    if (ptr1 != NULL && ptr2 == NULL)
    {
        return 1;
    }
    else if (ptr1 == NULL && ptr2 != NULL)
    {
        return -1;
    }
    while (L1 != NULL)
    {
        if (L1->digit < L2->digit)
        {
            return -1;
        }
        else if (L1->digit > L2->digit)
        {
            return 1;
        }
        L1 = L1->next;
        L2 = L2->next;
    }
    return 0;
}

dyn_array *ex2(int *A, int sz, int n)
{
    int mod, i;
    dyn_array *res = (dyn_array *)calloc(n - 1, sizeof(dyn_array)); // because n - 2 + 1
    for (mod = 2; mod <= n; mod++)
    {
        res[mod - 2].ptr = (int *)calloc(sz, sizeof(int));
        for (i = 0; i < sz; i++)
        {
            if (A[i] % mod == 0)
            {
                res[mod - 2].ptr[res[mod - 2].size] = A[i];
                (res[mod - 2].size)++;
            }
        }
        res[mod - 2].ptr = (int *)realloc(res[mod - 2].ptr, res[mod - 2].size * sizeof(int));
    }
    return res;
}

int ex3(char *file_name, char *word)
{
    FILE *fin = fopen(file_name, "r");
    if (!fin)
    {
        exit(1);
    }
    int i = 0;
    char c;
    while ((c = fgetc(fin)) != EOF)
    {
        if (c == word[0])
        {
            i++;
            break;
        }
    }
    if (i == 0)
    {
        fclose(fin);
        return 0;
    }
    while (word[i] != '\0')
    {
        if ((c = fgetc(fin)) == word[i])
        { // right
            i++;
        }
        else
        { // left
            if (c != EOF)
            {
                fseek(fin, -1, SEEK_CUR);
            }
            if (ftell(fin) - 2 < 0) // there is no letter on left
            {
                fclose(fin);
                return 0;
            }
            fseek(fin, -2, SEEK_CUR); // there is a letter on left so we need to go read it
            if ((c = fgetc(fin)) == word[i])
            {
                i++;
            } else {
                fclose(fin);
                return 0;
            }
        }
    }
    fclose(fin);
    return 1;
}