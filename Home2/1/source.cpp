#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ��������� ��������� � ���������� ����� ����� �� ��������.*/

	//��� ���������
	int a;
	printf("������� �����: ");
	scanf_s("%d", &a);
	if (a % 2 == 0)
		printf("����� ������");
	else
		printf("����� ��������");

	_getch();
}