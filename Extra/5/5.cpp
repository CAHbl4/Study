#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� ����������, ������ ������� �� 100 �� � ��������� ���� ����� �������.
	������� �� ����� ������������� ������� �� ���������� ������� �� ������ ����� �������.
	*/

	//��� ���������

	double s, f100, gas1, gas2, gas3;
	cout << "������� ����������: ";
	if (!(cin >> s)) {
		cout << "������ �����! ";
		system("pause");
		return;
	}
	if (s <= 0) {
		cout << "���������� ������ ���� ������ 0! ";
		system("pause");
		return;
	}

	cout << "������� ������ ������� �� 100 ��: ";
	if (!(cin >> f100)) {
		cout << "������ �����! ";
		system("pause");
		return;
	}
	if (f100 <= 0) {
		cout << "������ ������ ���� ������ 0! ";
		system("pause");
		return;
	}

	cout << "������� ��������� �������� (80 92 95): ";
	if (!(cin >> gas1 >> gas2 >> gas3)) {
		cout << "������ �����! ";
		system("pause");
		return;
	}
	if (gas1 <= 0 || gas2 <= 0 || gas3 <= 0) {
		cout << "��������� ������ ���� ������ 0! ";
		system("pause");
		return;
	}

	cout << "����������\t��-80\t��-92\t��-95" << endl;
	cout << s << "\t\t" << 100 / s * f100 * gas1 << "\t" << 100 / s * f100 * gas2 << "\t" << 100 / s * f100 * gas3 << "\t";


	cout << endl;
	system("pause");
}