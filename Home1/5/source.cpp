#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	int a, b, c;
	printf("Введите значение:");
	scanf_s("%d", &a);
	b = a;
	b *= a;
	c = b;
	c *= a;
	printf("\nКвадрат: %d \tКуб: %d", b, c);
	_getch();
}