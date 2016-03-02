#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	bool boolean = 25; // переменная типа bool с именем boolean
	if (boolean)
		cout << "true = " << boolean << endl;
	else
		cout << "false = " << boolean << endl;

	cout << sizeof(bool) << '\n' << sizeof(boolean);

	system("pause");
}