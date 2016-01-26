#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вася работает программистом и получает 50$ за каждые 100 строк кода. За каждое третее опоздание Васю штрафуют на 20$. Реализовать меню:
	- пользователь вводит желаемый доход Васи и количество опозданий, посчитать, сколько строк кода ему надо написать
	- пользователь вводит количество строк кода, написанное Васей и желаемый объем зарплаты. Посчитать, сколько раз Вася может опоздать
	- пользователь вводит количество строк кода и количество опозданий, определить, сколько денег заплатят Васе и заплатят ли вообще.

	*/

	//Код программы
	int op;
	cout << "1. Пользователь вводит желаемый доход Васи и количество опозданий, посчитать, сколько строк кода ему надо написать" << endl;
	cout << "2. Пользователь вводит количество строк кода, написанное Васей и желаемый объем зарплаты. Посчитать, сколько раз Вася может опоздать" << endl;
	cout << "3. Пользователь вводит количество строк кода и количество опозданий, определить, сколько денег заплатят Васе и заплатят ли вообще." << endl;
	cout << "Выберите действие: ";

	if (cin >> op) {
		switch (op)
		{
		case 1:
			int inc, lates, lines;
			cout << "Введите желаемый доход: ";
			cin >> inc;
			cout << "Введите количество опозданий: ";
			cin >> lates;
			lines = (inc - (lates / 3) * 20) / 50 * 100;
			cout << "Необходимо написать " << lines << " строк кода";
			break;

		default:
			cout << "Неверный выбор";
			break;
		}
	}
	else cout << "Ошибка ввода!";


	cout << endl;
	system("pause");
}