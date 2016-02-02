#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает два целых числа, и возвращает их произведение.

*/

int mult(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << mult(2, 3);

	cout << endl;
	system("pause");
}

int mult(int a, int b) {
	return a * b;
}