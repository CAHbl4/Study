#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Написать программу, которая проверяет введенное с клавиатуры целое число на четность.*/

	//Код программы
	int a;
	printf("Введите число: ");
	scanf_s("%d", &a);
	if (a % 2 == 0)
		printf("Число четное");
	else
		printf("Число нечетное");

	_getch();
}