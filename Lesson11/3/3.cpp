#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��� ������� ������������ ����� � ���������� �� m �� n ������� ��� ��������, ����� ������� � ������ �����. m � n �������� � ����������.
	*/

	//��� ���������

	int m, n;
	cout << "������� m � n: ";
	if (cin >> m >> n) {
		cout << "������ ������� �����: " << endl;
		for (; m <= n; m++) {
			cout << m << ":";
			for (int i = 2; i <= m / 2; i++) {
				if (!(m % i)) cout << i << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "������ �����";
	}

	cout << endl;
	system("pause");
}