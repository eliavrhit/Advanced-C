#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct student
{
	char name[30];
	int id_card;
	int grade;
} student;

#define N 5

void insertStudents(student students[], int num);
void printStudents(student students[]);
int calcAvg(student students[], int size, double* avg);

int main()
{
	student studentsData[N];
	double avg;
	int belowAvg;

	insertStudents(studentsData, N);
	belowAvg = calcAvg(studentsData, N, &avg);
	printf("\nThere are %d student(s) with grades below the avarage.\n", belowAvg);
	printf("\nThe average: %.1lf\n", avg);

	return 0;
}

void insertStudents(student students[], int num)
{
	int i;
	for (i = 0; i < num; i++)
	{
		printf("Please enter the name of student #%d: ", i + 1);
		scanf("%s", students[i].name);
		printf("Please enter ID of student #%d: ", i + 1);
		scanf("%d", &students[i].id_card);
		printf("Please enter grade of student #%d: ", i + 1);
		scanf("%d", &students[i].grade);
		printf("\n");
	}
}

void printStudents(student students[])
{
	int i;
	for (i = 0; i < N; i++)
	{
		printf("Student #%d name: %s\n", i + 1, students[i].name);
		printf("Student #%d ID: %d\n", i + 1, students[i].id_card);
		printf("Student #%d grade: %d\n", i + 1, students[i].grade);
	}
}

int calcAvg(student students[], int size, double* avg)
{
	int aboveAvg = 0, i;

	*avg = 0;
	for (i = 0; i < size; i++)
		*avg += students[i].grade;
	*avg /= size;

	printf("Students with grades above (or equal) the avarage:\n");
	for (i = 0; i < size; i++)
		if (*avg <= students[i].grade)
		{
			printf("#%d. Student name: %s, ID: %d\n", aboveAvg + 1, students[i].name, students[i].id_card);
			aboveAvg++;
		}

	return size - aboveAvg;
}