#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает два массива одинаковой длинны и поэлементно перемножает их.
Результат работы она записывает в элементы первого массива.

*/

void multiply(int a[], int b[], int n) {
	for (int i = 0; i < n; i++)
	{
		a[i] = a[i] * b[i];
	}
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 5;
	int a[N], b[N];

	for (int i = 0; i < N; i++) {
		a[i] = rand() % 10;
		b[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	multiply(a, b, N);

	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	system("pause");
}