#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���� ����������� ����� N. ���������� ����� ������� ����� � �� ������� � ����� (N=573863, ���������� �������� ����� 8, �� ������� ���������� �����).
	*/

	//��� ���������

	int n, max = 0, pos, count = 0;
	cout << "������� N: ";
	if (cin >> n) {
		do {
			count++;
			if (n % 10 > max) {
				max = n % 10; pos = count;
			}
			n /= 10;
		} while (n);
		cout << "���������� ����� " << max << " � " << pos << " �������";
	}
	else cout << "������ �����!";

	cout << endl;
	system("pause");
}