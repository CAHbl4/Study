#include <iostream>
using namespace std;

/*
Создать 2 целые переменные и определить «расстояние» между ними в памяти.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, b;
	cout << &a << endl;
	cout << &b << endl;
	cout << "Расстояние = " << &a - &b;

	cout << endl;
	system("pause");
}