#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������� �� ����� ��� ����� �� ���� �� ���������� ������������� �����.

	*/

	//��� ���������

	int a;
	cout << "������� �����: ";
	if (cin >> a) {
		for (int i = 0; i <= a; i++)
			cout << i << " ";
	}
	else {
		cout << "������ �����";
		return;
	}



	cout << endl;
	system("pause");
}