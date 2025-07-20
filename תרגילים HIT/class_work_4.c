#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ex1
typedef struct complex
{
    double real;
    double img;
} Complex;

Complex input();
void output(Complex number);
Complex sum(Complex num1, Complex num2);
Complex sub(Complex num1, Complex num2);
Complex mult(Complex num1, Complex num2);

int main() {

    printf("num1: ");
    Complex num1 = input();
    printf("num2: ");
    Complex num2 = input();
    printf("num1: ");
    output(num1);
    printf("num2: ");
    output(num2);
    Complex sumNum = sum(num1, num2);
    printf("Sum: ");
    output(sumNum);
    Complex subNum = sub(num1, num2);
    printf("Subtraction: ");
    output(subNum);
    Complex multNum = mult(num1, num2);
    printf("Multiplication: ");
    output(multNum);

    return 0;

}

Complex input() {
    Complex number;
    printf("please enter a real number: \n");
    scanf("%lf", &number.real);
    printf("please enter a img number \n");
    scanf("%lf", &number.img);
    return number;
}

void output(Complex number) {
    if (number.img >= 0) {
        printf("%.2lf + %.2lfi \n", number.real, number.img);
    }
    else {
        printf("%.2lf - %.2lfi \n", number.real, -number.img);
    }
}
Complex sum(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real + num2.real;
    result.img = num1.img + num2.img;
    return result;
}
Complex sub(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real - num2.real;
    result.img = num1.img - num2.img;
    return result;
}
Complex mult(Complex num1, Complex num2) {
    Complex result;
    result.real = num1.real * num2.real - num1.img * num2.img;
    result.img = num1.real * num2.img + num1.img * num2.real;
    return result;
}


//ex2

typedef struct student
{
    char name[30];
    int id_card;
    double grade;
} Student;
int calculate(student students[4], double *avarage);

int main() {
    Student students[4] = {
    {"Eliav", 206646929, 95},
    {"Yoni", 206646930, 90},
    {"Moshe", 206646931, 85},
    {"Yoav", 206646932, 80},
    };
    double avarage = 0;
    calculate(students, &avarage);

    return 0;
}

int calculate(Student students[4], double *avarage) {

    *avarage = 0;
    int count = 0;
    for (int i = 0; i < 4; i++) {
        *avarage += students[i].grade;
    }
    *avarage /= 4;
    printf("avarage: %.2lf \n", *avarage);
    printf("These are the students whose grade is above the average: \n");
    for (int i = 0; i < 4; i++) {
        if (students[i].grade > *avarage) {
            printf("%d %s %d \n", i + 1, students[i].name, students[i].id_card);
        }
        else
            count++;
    }
    return count;
}

//ex3

typedef struct
{
    char address[30];
    int rooms;
    double price;
} apartment;
apartment* filterApartments(apartment apartments[3], int wantedRooms, double maxPrice, int *resultCount);

int main() {
    apartment apartments[3] = {
    {"Balfour 58", 4, 2500000},
    {"Harav Levi", 3, 2000000},
    {"Negba 28", 3, 1500000},
    };
    int wantedRooms = 3;
    double maxPrice = 2000000;
    int resultCount = 0;
    apartment* apart = filterApartments(apartments, wantedRooms, maxPrice, &resultCount);
    for (int i = 0; i < resultCount; i++) {
        printf("%s: %d rooms; price: %.2lf \n", apart[i].address, apart[i].rooms, apart[i].price);
    }
    free(apart);
    return 0;
}

apartment* filterApartments(apartment apartments[3], int wantedRooms, double maxPrice, int *resultCount) {
    int count = 0;
    for (int i = 0; i < 3; i++) {
        if (apartments[i].rooms == wantedRooms && apartments[i].price <= maxPrice) {
            count++;
        }
    }
    *resultCount = count;
    apartment* apart = (apartment*)malloc(count * sizeof(apartment));
    if (apart == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
    int j = 0;
    for (int i = 0; i < 3; i++) {
        if (apartments[i].rooms == wantedRooms && apartments[i].price <= maxPrice) {
            apart[j] = apartments[i];
            j++;
        }
    }
    return apart;
}