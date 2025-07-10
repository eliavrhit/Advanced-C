#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void* realloc1(void* memblock, unsigned size_old, unsigned size_new);
int* arrcat(int* arr1, unsigned size1, int* arr2, unsigned size2);

int main()
{
	double* pd, * pd2;
	unsigned size = 8, new_size, i;
	int* ps1, * ps2, * ps3;

	//Question no. 1 - test
	pd = (double*)calloc(size, sizeof(double));
	if (pd)
		for (i = 0; i < size; i++)
			pd[i] = 1.1 * i;
	else
		size = 0;
	new_size = size + 2;

	pd2 = (double*)realloc1(pd, size * sizeof(double), new_size * sizeof(double));
	if (pd2)
	{
		pd = pd2;
		pd[size] = 8.8;
		pd[size + 1] = 9.9;
	}
	else
		new_size = size;

	printf("Question 1 - array after reallocation:\n");
	for (i = 0; i < new_size; i++)
		printf("%.1lf   ", pd[i]);
	free(pd);

	// Question no. 2 - test
	ps1 = (int*)calloc(3, sizeof(int));
	assert(ps1);
	ps2 = (int*)calloc(4, sizeof(int));
	assert(ps2);
	for (i = 0; i < 3; i++)
		ps1[i] = i;
	for (i = 0; i < 4; i++)
		ps2[i] = 3 + i;

	ps3 = arrcat(ps1, 3, ps2, 4);
	if (ps3)
	{
		ps1 = ps3;
		printf("\n\nQuestion 2 - array after concatenation:\n");
		for (i = 0; i < 3 + 4; i++)
			printf("%d  ", ps1[i]);
	}
	printf("\n");

	free(ps1);
	free(ps2);
}

// Question no. 1
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

// Question no. 2
int* arrcat(int* arr1, unsigned size1, int* arr2, unsigned size2)
{
	unsigned i;

	arr1 = (int*)realloc1(arr1, size1 * sizeof(int), (size1 + size2) * sizeof(int));
	if (arr1)
		for (i = size1; i < size1 + size2; i++)
			arr1[i] = arr2[i - size1];
	return arr1;
}

