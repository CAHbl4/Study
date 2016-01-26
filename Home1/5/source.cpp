#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	int a, b, c;
	printf("¬ведите значение:");
	scanf_s("%d", &a);
	b = a;
	b *= a;
	c = b;
	c *= a;
	printf("\n вадрат: %d \t уб: %d", b, c);
	_getch();
}