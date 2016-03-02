#include <iostream>
using namespace std;

/*
2.	Используя указатели и оператор разыменования, определить знак числа, введённого с клавиатуры.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, *ptra = &a;
	cout << "Введите целое число: ";
	cin >> *ptra;
	cout << (*ptra >= 0 ? "Число положительное" : "Число отрицательное");

	cout << endl;
	system("pause");
}