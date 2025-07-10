#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct complex
{
	double real;
	double img;
} Complex;

void inputComplex(Complex* number);
void printComplex(Complex* number);
Complex sumComplex(Complex* number1, Complex* number2);
Complex subComplex(Complex* number1, Complex* number2);
Complex multComplex(Complex* number1, Complex* number2);

int main()
{
	Complex number1, number2, sumComp, subComp, multComp;

	printf("First complex number\n");
	inputComplex(&number1);
	printf("\nSecond complex number\n");
	inputComplex(&number2);
	printf("\nFirst complex number: ");
	printComplex(&number1);
	printf("\nSecond complex number: ");
	printComplex(&number2);
	//printf("\n");

	sumComp = sumComplex(&number1, &number2);
	printf("\n\nThe sum of the 2 complex numbers: ");
	printComplex(&sumComp);

	subComp = subComplex(&number1, &number2);
	printf("\nThe subtraction of the 2 complex numbers: ");
	printComplex(&subComp);

	multComp = multComplex(&number1, &number2);
	printf("\nThe multiplication of the 2 complex numbers: ");
	printComplex(&multComp);

	printf("\n");
	return 0;
}

void inputComplex(Complex* number)
{
	printf("Please enter a value for the real part\n");
	scanf("%lf", &(number->real));
	printf("Please enter a value for the img part\n");
	scanf("%lf", &(number->img));
}

void printComplex(Complex* number)
{
	if (number->real != 0 && number->img != 0)
		if (number->img > 0)
			printf("%.2lf+%.2lfi", number->real, number->img);
		else
			printf("%.2lf%.2lfi", number->real, number->img);
	else
		if (number->real != 0 && number->img == 0)
			printf("%.2lf", number->real);
		else
			if (number->real == 0 && number->img != 0)
				printf("%.2lfi", number->img);
			else // number->real == 0 && number->img == 0
				printf("0");
}

Complex sumComplex(Complex* number1, Complex* number2)
{
	Complex sumCom;
	sumCom.real = number1->real + number2->real;
	sumCom.img = number1->img + number2->img;
	return sumCom;
}

Complex subComplex(Complex* number1, Complex* number2)
{
	Complex subCom;
	subCom.real = number1->real - number2->real;
	subCom.img = number1->img - number2->img;
	return subCom;
}

Complex multComplex(Complex* number1, Complex* number2)
{
	Complex multCom;
	multCom.real = number1->real * number2->real - number1->img * number2->img;
	multCom.img = number1->img * number2->real + number1->real * number2->img;
	return multCom;
}
