#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Написать программу, которая принимает с клавиатуры два значения целого типа 
	и предоставляет пользователю выбор арифметической операции над этими значениями. 
	Результат арифметической операции и операнды выводит на экран.*/

	//Код программы
	int a, b;
	char op;
	printf("Введите операнды: ");
	scanf_s("%d%d", &a, &b);
	printf("Выберите операцию (+ - * /): ");
	scanf_s(" %c", &op, 1);
	switch (op)
	{
	case '+':
		printf("%d %c %d = %d", a, op, b, a + b);
		break;
	case '-':
		printf("%d %c %d = %d", a, op, b, a - b);
		break;
	case '*':
		printf("%d %c %d = %d", a, op, b, a* b);
		break;
	case '/':
		printf("%d %c %d = %d", a, op, b, a / b);
		break;
	default:
		printf("Неверная операция");
		break;
	}

	_getch();
}