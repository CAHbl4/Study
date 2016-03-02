#include <iostream>
using namespace std;

/*
Напишите программу вычисления функции, заданной следующим образом:
			1, n = 0
F(n, m)		-1, n < m
			2 * F(n - 1, m)

*/

int F(int, int);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << F(5, 3);

	cout << endl;
	system("pause");
}

int F(int n, int m) {
	if (n == 0) {
		return 1;
	}
	else if (n < m) {
		return -1;
	} else {
		return (2 * F(n - 1, m));
	}
}