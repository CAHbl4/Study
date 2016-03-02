#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает три массива целых чисел.
Выполнить поэлементное сложение элементов первых двух массивов, и результат занести в третий массив.

*/

void sum(int a[], int b[], int c[], int n) {
	for (int i = 0; i < n; i++)
	{
		c[i] = a[i] + b[i];
	}
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 5;
	int a[N], b[N], c[N];

	for (int i = 0; i < N; i++) {
		a[i] = rand() % 10;
		b[i] = rand() % 10;
	}


	sum(a, b, c, N);

	for (int i = 0; i < N; i++)
	{
		cout.width(3);
		cout << a[i] << " + " << b[i] << " = " << c[i] << endl;
	}

	cout << endl;
	system("pause");
}