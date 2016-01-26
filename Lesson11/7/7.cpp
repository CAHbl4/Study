#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вводится число. Преобразовать его в другое число, цифры которого будут следовать в обратном порядке по сравнению с введенным числом.

	*/

	//Код программы

	int a, b = 0;

	cout << "Введите число: ";
	if (cin >> a) {
		do {
			b = b * 10 + a % 10;
			a /= 10;
		} while (a);
		cout << b;
	}
	else cout << "Ошибка ввода!";

	cout << endl;
	system("pause");
}