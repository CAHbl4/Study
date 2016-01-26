#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит число. Определить, является ли оно четным.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		cout << "Число " << (a % 2 ? "нечетное" : "четное");
	}
	else { cout << "Ошибка ввода!"; }

	cout << endl;
	system("pause");
}