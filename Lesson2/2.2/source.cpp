#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Ввести возраст человека (от 1 до 100 лет) и вывести его вместе с последующим словом «год», «года» или «лет».*/

	//Код программы
	int a, b, c;

	printf("Введите возраст Васи: ");
	scanf_s("%d", &a);

	if (a > 0 && a < 20) {
		if (a == 1) c = 1;
		if (a >= 2 && a <= 4) c = 2;
		if (a >= 5 && a <= 20) c = 3;
	}
	else {
		b = a % 10;
		if (b == 1) c = 1;
		if (b >= 2 && b <= 4) c = 2;
		if (b == 0 || b >= 5 && b <= 9) c = 3;
	}

	if (c == 1)
		printf("Васе %d год\n", a);
	if (c == 2)
		printf("Васе %d года\n", a);
	if (c == 3)
		printf("Васе %d лет\n", a);

	_getch();
}