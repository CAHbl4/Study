#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, �������������� ���������� ������ � �������� ���� � �����.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";

	if (cin >> a) {
		int odd = 0 , even = 0;
		do {
			if (a % 10 % 2) even++;
			else odd++;
			a /= 10;
		} while (a);
		cout << "������: " << odd << endl << "��������: " << even;
	}
	else cout << "������ �����!";


	cout << endl;
	system("pause");
}