#include <iostream>
using namespace std;

/*
1.	�������� �������, ������� ���������� ��� �����.
*/

int cube(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a;
	cout << "������� �����: ";
	cin >> a;

	cout << "��� ����� = " << cube(a);

	cout << endl;
	system("pause");
}

int cube(int a) {
	return a * a * a;
}