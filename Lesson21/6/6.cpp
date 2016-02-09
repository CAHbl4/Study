#include <iostream>
using namespace std;

/*
Напишите рекурсивную функцию нахождения суммы цифр натурального числа.

*/

int func(int);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << func(333);

	cout << endl;
	system("pause");
}

int func(int a) {
	if (!(a / 10)) { return a; }
	else {
		return (a % 10) + func(a / 10);
	}
}