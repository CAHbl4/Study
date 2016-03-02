#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает три целых числа, и определяет большее из них.

*/

int max(int a, int b, int c);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << max(2, 3, 4);

	cout << endl;
	system("pause");
}

int max(int a, int b, int c) {
	if (a > b && a > c) return a;
	else if (b > c) return b;
	else return c;
}