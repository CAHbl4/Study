#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ��������� ����� ���� ����� �������� ����� � ���������, �������� �������������.*/

	//��� ���������

	int a, b, sum = 0;

	printf("������� ������ � ����� ���������: ");
	scanf_s("%d%d", &a, &b);

	while (a <= b) {
		if (a % 2) sum += a;
		a++;
	}

	printf("����� = %d", sum);

	_getch();
}