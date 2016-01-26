#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь с клавиатуры последовательно вводит целые числа. Как только пользователь ввел 0, необходимо показать на экран сумму всех введенных чисел.

	*/

	//Код программы
	int a, sum = 0;

	while (1) {
		if (cin >> a) {
			if (a == 0) break;
			else sum += a;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "Ошибка ввода" << endl;
		}
	}

	cout << "Сумма введнных чисел = " << sum;
	cout << endl;
	system("pause");
}