#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	cout << "x\tx^2\tx^3" << endl;
	for (int i = 1; i <= 8; i++) {
		cout << i << "\t" << i * i << "\t" << i * i * i << endl;
	}

	cout << endl;
	system("pause");
}