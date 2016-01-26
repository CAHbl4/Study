#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int n, count;
	printf("Введите целое число: ");
	scanf_s("%d", &n);
	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	printf("В числе %d нашли %d цифр", n, count);

	_getch();
}