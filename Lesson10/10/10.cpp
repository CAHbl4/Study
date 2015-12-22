#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры число, необходимо показать на экран сумму его цифр.

	*/

	//Код программы

	int a, sum = 0;
	cout << "Введите число: ";
	if (cin >> a) {
		while (a) {
			sum += a % 10;
			a /= 10;
		}
	}
	else {
		cout << "Ошибка ввода";
	}

	cout << "Сумма чисел = " << sum;

	cout << endl;
	system("pause");
}