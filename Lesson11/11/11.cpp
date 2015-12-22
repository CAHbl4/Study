#include <iostream>

using namespace std;

unsigned long long fib(int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Числа Фибоначчи – это элементы числовой последовательности 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …, в которой каждое последующее число равно сумме двух предыдущих.
	Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.

	*/

	//Код программы

	int n;
	cout << "Введите n: ";
	if (cin >> n) {
		cout << fib(n);
	}
	else cout << "Ошибка ввода";

	cout << endl;
	system("pause");
}

unsigned long long fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}