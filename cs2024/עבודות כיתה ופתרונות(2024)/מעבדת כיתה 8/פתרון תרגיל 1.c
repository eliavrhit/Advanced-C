#include <stdio.h>
#include <string.h>

void swap(char* x, char* y);
int inversion(char* str);

void main()
{
	char str[30];

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';

	printf("%s\nString after inversion: %s\n", inversion(str) ? "Palindrome" : "Isn't palindrome", str);
}

void swap(char* x, char* y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

int inversion(char* str)
{
	char* end;
	int pal = 1;

	for (end = str + strlen(str) - 1; str < end; str++, end--)
		if (*str != *end)
		{
			swap(str, end);
			pal = 0;
		}
	return pal;
}