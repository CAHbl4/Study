#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ �����. ����������, �������� �� ��� �������. ����� ���������� �������, ���� ��� ������� ������ �� ���� � �� �������.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {
		for (int i = 2; i <= a / 2; i++) {
			if (!(a % i)) {
				cout << "����� ���������" << endl;
				system("pause");
				return;
			}
		}
		cout << "����� �������";
	}
	else {
		cout << "������ �����";
	}

	cout << endl;
	system("pause");
}