#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ � ���������� ��������������� ������ ����� �����. ��� ������ ������������ ���� 0, ���������� �������� �� ����� ����� ���� ��������� �����, ������� ������ 5.

	*/

	//��� ���������

	int a, sum = 0;

	while (1) {
		if (cin >> a) {
			if (a == 0) break;
			else if (!(a % 5)) sum += a;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "������ �����" << endl;
		}
	}

	cout << "����� ��������� �����, ������� ������ 5 = " << sum;

	cout << endl;
	system("pause");
}