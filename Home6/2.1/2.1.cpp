#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ ������� ��� � ��� ��� ��������. ���������, ������� ��� ������������.

	*/

	//��� ���������

	int current_year, birth_year;

	cout << "������� ������� ���: ";
	cin >> current_year;
	if (current_year < 1) cout << "� �� ����� ����������� �� ����";
	else {
		cout << "������� ��� ��������: ";
		cin >> birth_year;
		if (birth_year > current_year) cout << "�� ��� �� ��������";
		else cout << "��� " << current_year - birth_year << " ���";
	}

	cout << endl;
	system("pause");
}