#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	char symbol = 'a';
	// ���������� ���������� ���� char � ������������� � �������� 'a'
	cout << "symbol = " << symbol << endl;
	// ������ �������, ������������� � ���������� symbol

	cout << sizeof(char) << '\n' << sizeof(symbol);

	system("pause");
}