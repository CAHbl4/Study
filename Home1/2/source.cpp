#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	float a, b;
	printf("¬ведите сумму:");
	scanf_s("%f", &a);
	printf("\n¬ведите курс:");
	scanf_s("%f", &b);
	printf("\n%.2f: USD = %.2f BYR", a, a*b);
	_getch();
}