#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� ����� - ��������� ������ �������� ������� � ������ ����� ����.

	*/

	//��� ���������


	int a, count = 1;
	cout << "������� �����: ";
	if (cin >> a) {
		cout << "� ����� " << a;
		while (a /= 10) {
			count++;
		}
		cout << " " << count << " ����";
	}
	else {
		cout << "������ �����";
	}

	cout << endl;
	system("pause");
}