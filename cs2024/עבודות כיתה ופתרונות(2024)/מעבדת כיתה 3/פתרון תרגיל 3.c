#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef struct {
	char address[30];
	int rooms;
	double price;
} apartment;

apartment* approp_apart(apartment apart_units[], int n, int room_num, double lim_price, int* count);

#define N 5

void main()
{
	int room_num, approp_num, i;
	double lim_price;
	apartment apart_units[N], * approp_apart_units;

	for (i = 0; i < N; i++)
	{
		printf("\nApartment %d\n", i + 1);

		printf("Address: ");
		rewind(stdin);
		gets(apart_units[i].address);

		printf("Number of rooms: ");
		scanf("%d", &apart_units[i].rooms);

		printf("Price: ");
		scanf("%lf", &apart_units[i].price);
	}

	printf("\nNow many rooms do you want?  ");
	scanf("%d", &room_num);
	printf("\nMaximum price?  ");
	scanf("%lf", &lim_price);

	approp_apart_units = approp_apart(apart_units, N, room_num, lim_price, &approp_num);

	printf("\n%d Appropriate apartments:\n\n", approp_num);
	for (i = 0; i < approp_num; i++)
		printf("%s: %d rooms; price: %.2lf\n", approp_apart_units[i].address,
			approp_apart_units[i].rooms, approp_apart_units[i].price);

	free(approp_apart_units);
}

apartment* approp_apart(apartment apart_units[], int n, int room_num, double lim_price, int* count)
{
	int i;
	*count = 0;
	apartment* approp_apart_units; 
	
	approp_apart_units = (apartment*)calloc(n, sizeof(apartment));
	assert(approp_apart_units);

	for (i = 0; i < n; i++)
		if (apart_units[i].rooms == room_num && apart_units[i].price <= lim_price)
			approp_apart_units[(*count)++] = apart_units[i];
	approp_apart_units = (apartment*)realloc(approp_apart_units, *count * sizeof(apartment));

	return approp_apart_units;
}

			
			
			