#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*������ ������� �������� (�� 1 �� 100 ���) � ������� ��� ������ � ����������� ������ ����, ����� ��� ����.*/

	//��� ���������
	int a, b, c;

	printf("������� ������� ����: ");
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
		printf("���� %d ���\n", a);
	if (c == 2)
		printf("���� %d ����\n", a);
	if (c == 3)
		printf("���� %d ���\n", a);

	_getch();
}