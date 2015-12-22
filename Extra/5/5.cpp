#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры расстояние, расход бензина на 100 км и стоимость трех видов бензина.
	Вывести на экран сравнительную таблицу со стоимостью поездки на разных видах бензина.
	*/

	//Код программы

	double s, f100, gas1, gas2, gas3;
	cout << "Введите расстояние: ";
	if (!(cin >> s)) {
		cout << "Ошибка ввода! ";
		system("pause");
		return;
	}
	if (s <= 0) {
		cout << "Расстояние должно быть больше 0! ";
		system("pause");
		return;
	}

	cout << "Введите расход бензина на 100 км: ";
	if (!(cin >> f100)) {
		cout << "Ошибка ввода! ";
		system("pause");
		return;
	}
	if (f100 <= 0) {
		cout << "Расход должен быть больше 0! ";
		system("pause");
		return;
	}

	cout << "Введите стоимость бензинов (80 92 95): ";
	if (!(cin >> gas1 >> gas2 >> gas3)) {
		cout << "Ошибка ввода! ";
		system("pause");
		return;
	}
	if (gas1 <= 0 || gas2 <= 0 || gas3 <= 0) {
		cout << "Стоимость должна быть больше 0! ";
		system("pause");
		return;
	}

	cout << "Расстояние\tАИ-80\tАИ-92\tАИ-95" << endl;
	cout << s << "\t\t" << 100 / s * f100 * gas1 << "\t" << 100 / s * f100 * gas2 << "\t" << 100 / s * f100 * gas3 << "\t";


	cout << endl;
	system("pause");
}