#include <iostream>
#include <stdio.h>
#include <conio.h>

void main() {
	setlocale(LC_CTYPE, "Rus");
	int a, b, c;
	printf("������� ��������:");
	scanf_s("%d", &a);
	b = a;
	b *= a;
	c = b;
	c *= a;
	printf("\n�������: %d \t���: %d", b, c);
	_getch();
}