#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ �����. ����������, �������� �� ��� ������.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {
		cout << "����� " << (a % 2 ? "��������" : "������");
	}
	else { cout << "������ �����!"; }

	cout << endl;
	system("pause");
}