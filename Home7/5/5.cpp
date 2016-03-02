#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь с клавиатуры вводит оценку студента. Определить, допущен ли студент к экзамену.
	Студент получает допуск, если его оценка 4 балла и выше. Реализовать с помощью оператора if и оператора switch.

	*/

	//Код программы

	int a;
	cout << "Введите оценку: ";
	if (cin >> a && a >= 0) {
		cout << "Проверка с помощью if" << endl;
		if (a >= 4) cout << "Допуск есть";
		else cout << "Допуска нет";
		cout << endl << "Проверка с помощью switch" << endl;
		switch (a)
		{
		case 0: case 1: case 2: case 3:
			cout << "Допуска нет";
			break;
		default:
			cout << "Допуск есть";
			break;
		}
	}
	else cout << "Неверный ввод";


	cout << endl;
	system("pause");
}