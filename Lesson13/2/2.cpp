#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ ��� �����. ������� �� ����� ������� �� ���� �����.

	*/

	//��� ���������

	int a, b;
	cout << "������� �����: ";
	if (cin >> a >> b) {
		cout << "������� �����: " << (a < b ? a : b);
	}
	else { cout << "������ �����!"; }

	cout << endl;
	system("pause");
}