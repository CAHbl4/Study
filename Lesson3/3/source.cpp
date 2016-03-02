#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int i, j;
	for (i = 1, j = 1; i <= 10; j = j + i, i++) printf("%6d %6d %6d\n", j, j*j, j*j*j);

	_getch();
}