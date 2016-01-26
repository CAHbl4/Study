#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит число. Определить, является ли оно простым. Число называется простым, если оно делится только на себя и на единицу.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		for (int i = 2; i <= a / 2; i++) {
			if (!(a % i)) {
				cout << "Число непростое" << endl;
				system("pause");
				return;
			}
		}
		cout << "Число простое";
	}
	else {
		cout << "Ошибка ввода";
	}

	cout << endl;
	system("pause");
}