#include <iostream>
using namespace std;

/*
3.	�������� �������, ������� ���������� ������, ���� ������������ �������� ������������� � ����, ���� �������������.
*/

bool isPositive(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a;
	cout << "������� �����: ";
	cin >> a;

	cout << "����� " << a << (isPositive(a) ? " �������������" : " �������������");

	cout << endl;
	system("pause");
}

bool isPositive(int a) {
	return a >= 0;
}