#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� �����. ������������� ��� � ������ �����, ����� �������� ����� ��������� � �������� ������� �� ��������� � ��������� ������.

	*/

	//��� ���������

	int a, b = 0;

	cout << "������� �����: ";
	if (cin >> a) {
		do {
			b = b * 10 + a % 10;
			a /= 10;
		} while (a);
		cout << b;
	}
	else cout << "������ �����!";

	cout << endl;
	system("pause");
}