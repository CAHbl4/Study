#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, ������� �� ������ ������������ �������� ��������� �� ����� � ������� �� ������� �� ������� ������������. ��������� ������������ ����� ������.

	*/

	//��� ���������

	double x, result = 1;
	int y;

	cout << "������� �����: ";
	if (cin >> x) {
		cout << "������� ������� (0 - 7): ";
		if (cin >> y && y >= 0 && y <= 7) {
			cout << x << "^" << y << "=";
			while (y) {
				result *= x;
				y--;
			}
			cout << result;
		}
		else cout << "�������� ����";
	}
	else cout << "�������� ����";



	cout << endl;
	system("pause");
}

