#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << 7 / 4 << endl;

	cout << (float)7 / 4 << endl;
	cout << 7 / (float)4 << endl;

	cout << (double)7 / 4 << endl;
	cout << 7 / (double)4 << endl;

	cout << 25.5 / 5 << endl;
	cout << (int)25.5 / 5 << endl;

	cout << endl;
	system("pause");
}