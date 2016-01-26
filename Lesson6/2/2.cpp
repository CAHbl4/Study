#include <iostream>

using namespace std;

int x;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	const int   MaxMemSize = { 1000 * 8 + 10000 };
	register int   y = x * MaxMemSize;
	cout << y << endl;
	if (1) {
		int x = 3;
		y = x * MaxMemSize;
		cout << y << endl;
	}
	y = x * MaxMemSize;
	cout << y << endl;


	cout << endl;
	system("pause");
}