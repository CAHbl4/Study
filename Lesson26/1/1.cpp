#include <iostream>
using namespace std;

/*
������� 2 ����� ���������� � ���������� ����������� ����� ���� � ������.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a, b;
	cout << &a << endl;
	cout << &b << endl;
	cout << "���������� = " << &a - &b;

	cout << endl;
	system("pause");
}