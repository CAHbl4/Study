#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ����� � ���������� ������, ���� ����� ������ � ����, ���� ��������.

*/

bool isEven(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << isEven(3);

	cout << endl;
	system("pause");
}

bool isEven(int a) {
	return (a % 2) == 0;
}