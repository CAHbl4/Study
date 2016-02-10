#include <iostream>
using namespace std;

/*
Описать рекурсивную функцию вычисления НОД(n,m) - наибольшего общего делителя неотрицательных целых чисел n и m, 
основанную на соотношении НОД(n,m) = НОД(m,r), где r - остаток от деления n на m. С ее помощью найти наибольший общий делитель натуральных чисел a и b.

*/

int gcd(int n, int m);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << gcd(27, 9);

	cout << endl;
	system("pause");
}

int gcd(int n, int m) {
	if (m == 0) {
		return n;
	} else {
		return gcd(m, n % m);
	}
}