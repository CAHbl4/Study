#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ��� ����� �����, � ���������� �� ������������.

*/

int mult(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << mult(2, 3);

	cout << endl;
	system("pause");
}

int mult(int a, int b) {
	return a * b;
}