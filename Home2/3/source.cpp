#include <stdio.h>
#include <conio.h>
#include <iostream>

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ��������� � ���������� ��� �������� ������ ���� 
	� ������������� ������������ ����� �������������� �������� ��� ����� ����������. 
	��������� �������������� �������� � �������� ������� �� �����.*/

	//��� ���������
	int a, b;
	char op;
	printf("������� ��������: ");
	scanf_s("%d%d", &a, &b);
	printf("�������� �������� (+ - * /): ");
	scanf_s(" %c", &op, 1);
	switch (op)
	{
	case '+':
		printf("%d %c %d = %d", a, op, b, a + b);
		break;
	case '-':
		printf("%d %c %d = %d", a, op, b, a - b);
		break;
	case '*':
		printf("%d %c %d = %d", a, op, b, a* b);
		break;
	case '/':
		printf("%d %c %d = %d", a, op, b, a / b);
		break;
	default:
		printf("�������� ��������");
		break;
	}

	_getch();
}