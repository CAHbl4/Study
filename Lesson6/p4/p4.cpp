#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	int a = 5, b = 7, c = 9;
	c += a--*++b;
	cout << a << " " << b << " " << c << endl;

	cout << endl;
	system("pause");
}