#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, b;
	a = 10; b = 5;
	printf("%d\t%d\n", a, b);
	printf("%d\t%d\n", (a++) * 2, (b--) * 2);
	printf("%d\t%d", (++a) * 2, (--b) * 2);
	_getch();

	_getch();
}