#include <stdio.h>
#include <string.h>
#include <ctype.h>

void str_analysis(char* str, int* small, int* big, int* digit, int* other);

void main()
{
	char str[30];
	int num_small_let, num_big_let, num_dig, num_other;

	printf("Enter string: ");
	fgets(str, sizeof(str), stdin);
	str[strlen(str) - 1] = '\0';

	str_analysis(str, &num_small_let, &num_big_let, &num_dig, &num_other);

	printf("%d small letters\n%d big letters\n%d digits\n%d other characters\n",
		num_small_let, num_big_let, num_dig, num_other);
}

void str_analysis(char* str, int* small, int* big, int* digit, int* other)
{
	*small = *big = *digit = *other = 0;
	for (; *str != '\0'; str++)
		if (islower(*str))
			(*small)++;
		else
			if (isupper(*str))
				(*big)++;
			else
				if (isdigit(*str))
					(*digit)++;
				else
					(*other)++;
}

