#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int x, r = 0;
	printf("������� �����: ");
	scanf_s("%d", &x);
	while (x) {
		r += x % 10;
		x = x / 10;
	}
	printf("����� ���� = %d", r);
	_getch();
}