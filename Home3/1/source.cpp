#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ������� �� ����� �������������� ����� ��������.
	��� ������� � ����� ����� ������������ ������ � ����������.*/
	
	//��� ���������
	int i = 0;
	char c;

	printf("������� ������: ");
	scanf_s("%c", &c);

	printf("������� ������: ");
	scanf_s("%d", &i);

	while (i < 1) {
		printf("�������� ������, ������� ��� ���: ");
		scanf_s(" %d", &i);
	}

	while (i) {
		printf("%c", c);
		i--;
	}

	_getch();
}