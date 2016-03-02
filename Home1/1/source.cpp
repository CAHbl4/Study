#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	const float INCHES = 2.54;
	float a;
	printf("Введите значение в дюймах:");
	scanf_s("%f", &a);
	printf("\n%.2f: дюймов = %.2f мм", a, a * INCHES);
	_getch();
}