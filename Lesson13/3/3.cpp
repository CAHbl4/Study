#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ �����. ����������, ������������� ��� �����, ������������� ��� ����� ����.
	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {
		if (a > 0) { cout << "����� �������������"; }
		else if (a == 0) { cout << "����� ����� 0"; }
		else if (a < 0) { cout << "����� �������������"; }
			
	}
	else { cout << "������ �����!"; }

	cout << endl;
	system("pause");
}