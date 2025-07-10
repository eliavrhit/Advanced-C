/*The program creates two dynamic strings:
one of capital letters and one of small letters*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

void Capital_small(char* a, char** Cap, char** small);

#define N 30

void main()
{
	char str[N], * str_Cap, * str_small;

	printf("Enter string: ");
	gets(str);

	Capital_small(str, &str_Cap, &str_small);

	printf("\nstring of CAPITAL letters: ");
	puts(str_Cap);
	printf("\nstring of small letters: ");
	puts(str_small);

	free(str_Cap);
	free(str_small);
}

void Capital_small(char* s, char** Cap, char** small)
{
	int i_Cap = 0, i_small = 0, i;

	for (i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			(i_Cap)++;
		else
			if (s[i] >= 'a' && s[i] <= 'z')
				(i_small)++;
	*Cap = (char*)malloc(i_Cap + 1);
	*small = (char*)malloc(i_small + 1);
	i_Cap = i_small = 0;
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] >= 'A' && s[i] <= 'Z')
			(*Cap)[i_Cap++] = s[i];
		else
			if (s[i] >= 'a' && s[i] <= 'z')
				(*small)[i_small++] = s[i];
	(*Cap)[i_Cap] = '\0';
	(*small)[i_small] = '\0';
}









