#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает число и возвращает истину, если число четное и ложь, если нечетное.

*/

bool isEven(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << isEven(3);

	cout << endl;
	system("pause");
}

bool isEven(int a) {
	return (a % 2) == 0;
}