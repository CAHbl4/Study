#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� �����, ���������� �������� �� ����� ����� ��� ����.

	*/

	//��� ���������

	int a, sum = 0;
	cout << "������� �����: ";
	if (cin >> a) {
		while (a) {
			sum += a % 10;
			a /= 10;
		}
	}
	else {
		cout << "������ �����";
	}

	cout << "����� ����� = " << sum;

	cout << endl;
	system("pause");
}