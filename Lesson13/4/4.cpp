#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ ��� �����. ����������, ����� �� ��� �����, � ���� ���, ������� �� �� ����� � ������� �����������.

	*/

	//��� ���������

	int a, b;
	cout << "������� �����: ";
	if (cin >> a >> b) {
		if (a == b) { cout << "����� �����"; }
		else if (a > b){
			cout << a << " " << b;
		}
		else {
			cout << b << " " << a;
		}
	}
	else { cout << "������ �����!"; }

	cout << endl;
	system("pause");
}