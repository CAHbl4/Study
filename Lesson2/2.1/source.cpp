#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Ввести номер месяца и вывести название времени года.*/

	//Код программы
	int a;
	printf("Введите номер месяца: ");
	scanf_s("%d", &a);

	a %= 3;
	if (a / 3 == 1 || a == 14) printf("Зима\n");
	else if (a / 3 == 2)
		printf("Весна\n");
	else if (a / 3 == 3)
		printf("Лето\n");
	else if (a / 3 == 4)
		printf("Осень\n");
	else
		printf("Неверный месяц");

	_getch();
}