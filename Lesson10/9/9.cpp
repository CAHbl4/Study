#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры число, необходимо вывести на экран перевернутое число.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {

		while (a) {
			cout << a % 10;
			a /= 10;
		}
	}
	else {
		cout << "Ошибка ввода";
	}

	cout << endl;
	system("pause");
}