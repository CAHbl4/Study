#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*������ ����� ������ � ������� �������� ������� ����.*/

	//��� ���������
	int a;
	printf("������� ����� ������: ");
	scanf_s("%d", &a);

	a %= 3;
	if (a / 3 == 1 || a == 14) printf("����\n");
	else if (a / 3 == 2)
		printf("�����\n");
	else if (a / 3 == 3)
		printf("����\n");
	else if (a / 3 == 4)
		printf("�����\n");
	else
		printf("�������� �����");

	_getch();
}