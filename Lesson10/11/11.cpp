#include <iostream>

using namespace std;

float exp(int x, int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� �������� ����� � �������. ������ ������������� �������.

	*/

	//��� ���������

	int x, y;
	cout << "������� �����: ";
	if (cin >> x) {
		cout << "������� �������: ";
		if (cin >> y) {
			cout << x << "^" << y << " = " << exp(x, y);
		}
		else {
			cout << "������ �����" << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << "������ �����" << endl;
		system("pause");
		return;
	}

	cout << endl;
	system("pause");
}

float exp(int x, int y) {
	int i;
	float result = 1.0;
	if (y < 0) {
		for (i = 0; i < -y; i++) {
			result *= x;
		}
		result = 1 / result;
	}
	else if (y > 0) {
		for (i = 0; i < y; i++) {
			result *= x;
		}
	}
	return result;
}