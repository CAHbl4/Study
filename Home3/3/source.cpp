#include <stdio.h>
#include <conio.h>
#include <iostream>

float exp(int x, int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ����������� ��� ����� ����� x � y, 
	����� ���� ��������� � ������� �������� x � ������� y.*/

	//��� ���������

	int x, y;

	printf("������� x � y: ");
	scanf_s("%d%d", &x, &y);

	printf(" %d ^ %d = %g", x, y, exp(x, y));

	_getch();
}

float exp(int x, int y) {
	int i;
	float result = 1.0;
	if (y < 0) {
		for (i = 0; i < -y; i++) {
			result *= x;
		}
		result = 1 / result;
	}
	else if (y > 0) {
		for (i = 0; i < y; i++) {
			result *= x;
		}
	}
	return result;
}