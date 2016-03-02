#include <iostream>
using namespace std;

/*
1.	Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, b;
	int *ptra = &a, *ptrb = &b;
	cout << "Введите a и b: ";
	cin >> *ptra >> *ptrb;
	cout << (*ptra > *ptrb ? "а больше b" : "b больше a");

	cout << endl;
	system("pause");
}