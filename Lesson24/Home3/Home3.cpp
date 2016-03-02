#include <iostream>
using namespace std;

/*
3.	Используя указатели и оператор разыменования, обменять местами значения двух переменных.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, *ptra = &a, b, *ptrb = &b;
	cout << "Введите a и b: ";
	cin >> *ptra >> *ptrb;
	int tmp = *ptra;
	*ptra = *ptrb;
	*ptrb = tmp;
	cout << "a = " << *ptra << " b = " << *ptrb;

	cout << endl;
	system("pause");
}