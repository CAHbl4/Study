#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������� �� ����� ���� ����� �� A �� B.

	*/

	//��� ���������

	int a, b;

	cout << "������� A � B: ";
	if (cin >> a >> b) {
		cout << "A\tA^3" << endl;
		for (; a <= b; a++) {
			cout << a << "\t" << a * a * a << endl;
		}
	}
	else {
		cout << "������ �����";
	}



	cout << endl;
	system("pause");
}