#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���� ���� ������ ���, ������� ���, ������� �������. �������� ���������, ������� ����������, ������� ��� ������� ���� � �������� �� �������.

	*/

	//��� ���������
	int count = 0;

	for (int i = 1; i <= 12; i++) {
		count += i;

	}
	cout << "���� ������� " << count << " ���";

	cout << endl;
	system("pause");
}