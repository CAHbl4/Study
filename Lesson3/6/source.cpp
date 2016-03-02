#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int i;
	char c;

	printf("Введите длинну: ");
	scanf_s("%d", &i);
	printf("Введите символ: ");
	scanf_s(" %c", &c);
	while (i){
		printf("%c", c);
		i--;
	}

	_getch();
}