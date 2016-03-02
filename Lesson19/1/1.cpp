#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает два целых числа, и возвращает их сумму.

*/
int sum(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a = 2, b = 3;
	cout << sum(a, b);


	cout << endl;
	system("pause");
}

int sum(int a, int b) {
	return a + b;
}