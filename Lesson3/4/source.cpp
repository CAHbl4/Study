#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int n, count;
	printf("������� ����� �����: ");
	scanf_s("%d", &n);
	count = 0;
	while (n != 0)
	{
		count++;
		n = n / 10;
	}
	printf("� ����� %d ����� %d ����", n, count);

	_getch();
}