#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int i;
	char c;

	printf("������� ������: ");
	scanf_s("%d", &i);
	printf("������� ������: ");
	scanf_s(" %c", &c);
	while (i){
		printf("%c", c);
		i--;
	}

	_getch();
}