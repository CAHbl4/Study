#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ � ���������� ������ ������ ��������. ����������, ������� �� ������� � ��������.
	������� �������� ������, ���� ��� ������ 4 ����� � ����. ����������� � ������� ��������� if � ��������� switch.

	*/

	//��� ���������

	int a;
	cout << "������� ������: ";
	if (cin >> a && a >= 0) {
		cout << "�������� � ������� if" << endl;
		if (a >= 4) cout << "������ ����";
		else cout << "������� ���";
		cout << endl << "�������� � ������� switch" << endl;
		switch (a)
		{
		case 0: case 1: case 2: case 3:
			cout << "������� ���";
			break;
		default:
			cout << "������ ����";
			break;
		}
	}
	else cout << "�������� ����";


	cout << endl;
	system("pause");
}