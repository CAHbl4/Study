#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ � ���������� ��������������� ������ ����� �����. ��� ������ ������������ ���� 0, ���������� �������� �� ����� ������� �������������� ���� ��������� �����.

	*/

	//��� ���������

	int a, sum = 0, count = 0;

	while (1) {
		if (cin >> a) {
			if (a == 0) break;
			sum += a;
			count++;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "������ �����" << endl;
		}
	}

	cout << "������� �������������� ��������� ����� = " << (double)sum / count;

	cout << endl;
	system("pause");
}