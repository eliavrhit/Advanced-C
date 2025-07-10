/*The program creates two linked lists:
one of even numbers and one of odd numbers
The program calculates sum, min, and max for each list*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>

typedef struct element
{
	int data;
	struct element* ptr_next;
} element;

int even_odd(element**, element**);
int sum_min_max(element* lst, int* min, int* max);
void print_list(element* lst);
void free_list(element* lst);

void main()
{
	element* even_num_list, * odd_num_list;
	int min_even, max_even, sum_even, min_odd, max_odd, sum_odd,
		num = even_odd(&even_num_list, &odd_num_list);

	sum_even = sum_min_max(even_num_list, &min_even, &max_even);
	sum_odd = sum_min_max(odd_num_list, &min_odd, &max_odd);

	printf("\n%d numbers:\n", num);
	printf("even_numbers: ");
	print_list(even_num_list);
	if (even_num_list)
		printf("\n(sum=%d min=%d max=%d)\n", sum_even, min_even, max_even);
	else
		printf("\n(sum=%d)\n", sum_even);
	printf("odd_numbers: ");
	print_list(odd_num_list);
	if (odd_num_list)
		printf("\n(sum=%d min=%d max=%d)\n", sum_odd, min_odd, max_odd);
	else
		printf("\n(sum=%d)\n", sum_odd);

	free_list(even_num_list);
	free_list(odd_num_list);
}

int even_odd(element** even_list, element** odd_list)
{
	element* even_ptr, * odd_ptr;
	int count = 0, x;

	*even_list = (element*)malloc(sizeof(element)); //dummy for list of even
	*odd_list = (element*)malloc(sizeof(element)); //dummy for list of odd
	even_ptr = *even_list;
	odd_ptr = *odd_list;

	printf("Enter numbers: ");
	scanf("%d", &x);
	while (x != -1)
	{
		if (x % 2 == 0)
		{
			even_ptr->ptr_next = (element*)malloc(sizeof(element));
			even_ptr = even_ptr->ptr_next;
			even_ptr->data = x;
		}
		else
		{
			odd_ptr->ptr_next = (element*)malloc(sizeof(element));
			odd_ptr = odd_ptr->ptr_next;
			odd_ptr->data = x;
		}
		count++;
		scanf("%d", &x);
	}
	even_ptr->ptr_next = odd_ptr->ptr_next = NULL;

	/* delete of dummies */
	even_ptr = *even_list;
	*even_list = (*even_list)->ptr_next;
	free(even_ptr);
	odd_ptr = *odd_list;
	*odd_list = (*odd_list)->ptr_next;
	free(odd_ptr);

	return count;
}

int sum_min_max(element* lst, int* min, int* max)
{
	int sum = 0;
	if (lst)
		* min = *max = lst->data;
	while (lst)
	{
		if (lst->data < *min)
			* min = lst->data;
		else
			if (lst->data > * max)
				* max = lst->data;
		sum += lst->data;
		lst = lst->ptr_next;
	}
	return sum;
}


void print_list(element* lst)
{
	while (lst)
	{
		printf("%d ", lst->data);
		lst = lst->ptr_next;
	}
}

void free_list(element* lst)
{
	element* temp;

	while (lst)
	{
		temp = lst;
		lst = lst->ptr_next;
		free(temp);
	}
}






