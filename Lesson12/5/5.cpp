#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ������. ������� ����� ������ �����, ����� � �����, ���� ����� �� ���� 10 ������,
	�� ������ � 5 ������, �� ������� - 0,5 �����. ���� �� 100 ������, ���� ������ 100 ����� �����.

	*/

	//��� ���������
	int bull = 1, cow = 1, calf = 1;

	for (; bull < 10; bull++) {
		for (; cow < 20; cow++) {
			calf = 100 - (bull + cow);
			if (bull * 20 + cow * 10 + calf == 200) {
				cout << "�����: " << bull << endl;
				cout << "�����: " << cow << endl;
				cout << "�����: " << calf << endl;
			}
		}

	}


	cout << endl;
	system("pause");
}