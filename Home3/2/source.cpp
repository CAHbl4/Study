#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Написать программу, которая вычисляет сумму всех целых нечетных чисел в диапазоне, заданном пользователем.*/

	//Код программы

	int a, b, sum = 0;

	printf("Введите начало и конец диапазона: ");
	scanf_s("%d%d", &a, &b);

	while (a <= b) {
		if (a % 2) sum += a;
		a++;
	}

	printf("Сумма = %d", sum);

	_getch();
}