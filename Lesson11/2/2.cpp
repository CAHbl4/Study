#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���� ������������������ �����, ��������� ������ �� ���� 0 � 5, � ������� �����������: 0 5 50 55 500 505 5000 5005 5050 � ��� �����. ����� k-�� �� ������� � ���� ������������������ �����.
	��������

	*/

	//��� ���������

	int k;

	cout << "������� �����: ";
	if (cin >> k) {
		unsigned long long a = 0, b;
		int i = 0;
		while (i <= k - 1) {
			a += 5;
			b = a;
			do {
				if (b % 10 != 5 && b % 10 != 0) break;
				b /= 10;
				if (b == 0) i++;
			} while (b > 0);
		}
		cout << a;
	}
	else {
		cout << "������ �����";
	}



	cout << endl;
	system("pause");
}