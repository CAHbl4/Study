#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит два числа. Вывести на экран меньшее из этих чисел.

	*/

	//Код программы

	int a, b;
	cout << "Введите числа: ";
	if (cin >> a >> b) {
		cout << "Меньшее число: " << (a < b ? a : b);
	}
	else { cout << "Ошибка ввода!"; }

	cout << endl;
	system("pause");
}