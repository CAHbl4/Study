#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	bool boolean = 25; // ���������� ���� bool � ������ boolean
	if (boolean)
		cout << "true = " << boolean << endl;
	else
		cout << "false = " << boolean << endl;

	cout << sizeof(bool) << '\n' << sizeof(boolean);

	system("pause");
}