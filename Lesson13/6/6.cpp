#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� �����. ���� ��� ������, �������� ��� �� ���, ����� � �������� �� ���. ��������� ������� �� �����.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {
		if (a % 2) cout << a / 2;
		else cout << a * 3;
	}
	else { cout << "������ �����!"; }

	cout << endl;
	system("pause");
}