#include <iostream>
using namespace std;

/*
�������� ����������� ������� ���������� ����� ���� ������������ �����.

*/

int func(int);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << func(333);

	cout << endl;
	system("pause");
}

int func(int a) {
	if (!(a / 10)) { return a; }
	else {
		return (a % 10) + func(a / 10);
	}
}