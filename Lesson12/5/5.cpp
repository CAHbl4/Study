#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ������. ������� ����� ������ �����, ����� � �����, ���� ����� �� ���� 10 ������,
	�� ������ � 5 ������, �� ������� - 0,5 �����. ���� �� 100 ������, ���� ������ 100 ����� �����.

	*/

	//��� ���������
	int bull = 0, cow = 0, calf = 0;

	for (int count = 0; count < 100; count++) {
		if ((100 - bull * 10) / 0.5 > (100 - count)) bull++;
		else if ((100 - cow * 5) / 0.5 > (100 - count)) cow++;
		else calf++;
	}

	cout << "�����: " << bull << endl;
	cout << "�����: " << cow << endl;
	cout << "�����: " << calf << endl;

	cout << endl;
	system("pause");
}