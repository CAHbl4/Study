#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ � ���������� ��������������� ������ ����� �����. ��� ������ ������������ ���� 0, ���������� �������� �� ����� ����� ���� ��������� �����.

	*/

	//��� ���������
	int a, sum = 0;

	while (1) {
		if (cin >> a) {
			if (a == 0) break;
			else sum += a;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "������ �����" << endl;
		}
	}

	cout << "����� �������� ����� = " << sum;
	cout << endl;
	system("pause");
}