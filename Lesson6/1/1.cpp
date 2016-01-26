#include <iostream>

using namespace std;

int x;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	static int d;
	cout << d << endl;
	const int   MaxMemSize = { 1000 * 8 + 10000 };
	register int   y = x * MaxMemSize;
	cout << y << endl;
	int x = 3;
	y = x * MaxMemSize;
	cout << y << endl;

	cout << endl;
	system("pause");
}