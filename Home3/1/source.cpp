#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Написать программу, которая выводит на экран горизонтальную линию символов.
	Вид символа и длину линии пользователь вводит с клавиатуры.*/
	
	//Код программы
	int i = 0;
	char c;

	printf("Введите символ: ");
	scanf_s("%c", &c);

	printf("Введите длинну: ");
	scanf_s("%d", &i);

	while (i < 1) {
		printf("Неверная длинна, введите еще раз: ");
		scanf_s(" %d", &i);
	}

	while (i) {
		printf("%c", c);
		i--;
	}

	_getch();
}