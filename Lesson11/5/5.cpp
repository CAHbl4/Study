#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Составить таблицу значений функции y = 5 - x^2 / 2
	на отрезке [-5; 5] с шагом 0.5.

	*/

	//Код программы

	float x = -5., y;

	cout << "x\ty" << endl;
	for (; x <= 5; x += .5) {
		y = 5 - x * x / 2;
		cout << x << "\t" << y << endl;

	}

	cout << endl;
	system("pause");
}