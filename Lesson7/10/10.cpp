#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� �����, ���������� ����������� ����� � ������� �� �����.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {

		while (a) {
			cout << a % 10;
			a /= 10;
		}
	}
	else {
		cout << "������ �����";
	}

	cout << endl;
	system("pause");
}