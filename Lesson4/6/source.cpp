#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*�������� ���������, ������� ����������� ��������� � ���������� ������� ����� � �������� ������. 
	��������, ����� 12,5 ������ ���� ������������� � ���� 12���. 50 ���.*/

	//��� ���������

	float a;
	int i, d;

	cout << "������� �����: ";
	scanf_s("%g", &a);
	i = a;
	a = a - i;
	a = a * 100;
	d = a;

	cout << i << "���. " << d << "���." << endl;

	system("pause");
}