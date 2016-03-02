#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int x, r = 0;
	printf("Введите число: ");
	scanf_s("%d", &x);
	while (x) {
		r += x % 10;
		x = x / 10;
	}
	printf("Сумма цифр = %d", r);
	_getch();
}