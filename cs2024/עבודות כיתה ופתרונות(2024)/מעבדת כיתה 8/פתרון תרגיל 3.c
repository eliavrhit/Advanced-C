#include <stdio.h>
#include <malloc.h>
#include <string.h>

void delete_space(char* str);

void main()
{
	char str[100];

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';

	delete_space(str);

	printf("String after processing: %s\n", str);
}

void delete_space(char* str)
{
	int len = strlen(str), i, j;

	for (i = 1, j = 0; i <= len; i++)
		if (str[i] != ' ' || str[i - 1] != ' ')
		{
			j++;
			str[j] = str[i];
		}
}
