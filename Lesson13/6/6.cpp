#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры число. Если оно четное, умножить его на три, иначе – поделить на два. Результат вывести на экран.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		if (a % 2) cout << a / 2;
		else cout << a * 3;
	}
	else { cout << "Ошибка ввода!"; }

	cout << endl;
	system("pause");
}