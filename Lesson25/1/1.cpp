#include <iostream>
using namespace std;

/*
Написать функцию, которая меняет местами значения двух переменных.

*/

void swap(int *a, int *b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << "a = " << a << ", b = " << b;

	cout << endl;
	system("pause");
}

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
