#include <stdio.h>
#include <stdlib.h>

void* realloc1(void* memblock, unsigned size_old, unsigned size_new);
int* diffArrays(int* A, int n, int* B, int m, int* size);

int main()
{
	int A[] = { 5,7,10,15,2,4 }, B[] = { 1,5,2,24,56,70,71 }, n, m, *C, C_size, i;

	n = sizeof(A) / sizeof(int);
	m = sizeof(B) / sizeof(int);

	C = diffArrays(A, n, B, m, &C_size);

	printf("Array C (%d elements):\n", C_size);
	for (i = 0; i < C_size; i++)
		printf("%d ", C[i]);
	printf("\n");

	free(C);
}

void* realloc1(void* memblock, unsigned size_old, unsigned size_new)
{
	char* pc_old = (char*)memblock, * pc_new = (char*)malloc(size_new);
	int min_size = (size_old) < size_new ? size_old : size_new, i;

	if (pc_new && pc_old)
	{
		for (i = 0; i < min_size; i++)
			pc_new[i] = pc_old[i];
		free(memblock);
		if (size_new == 0)
			return NULL;
	}
	return pc_new;
}

int* diffArrays(int* A, int n, int* B, int m, int* size)
{
	int i, j, k = 0, * C;

	C = (int*)realloc1(NULL, 0, n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
			if (B[j] == A[i])
				break;
		if (j == m)
			C[k++] = A[i];
	}
	*size = k;
	C = (int*)realloc1(C, n * sizeof(int), *size * sizeof(int));
	return C;
}

