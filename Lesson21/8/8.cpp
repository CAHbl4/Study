#include <iostream>
using namespace std;

/*
Напишите программу вычисления функции, заданной следующим образом:
			1, n = 2
F (n,m)		m, n - odd
			F(n/2 + 1, m + n)
*/

int F(int, int);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << F(5, 6);

	cout << endl;
	system("pause");
}

int F(int n, int m) {
	if (n == 2) return 1;
	else if (!(n % 2)) return m;
	else return F(n / 2 + 1, m + n);
}