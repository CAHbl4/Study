#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Составить расписание на неделю. Пользователь вводит порядковый номер дня недели и у него на экране отображается, то, что запланировано на этот день.
	*/

	//Код программы

	int d;

	cout << "Введите номер дня недели: ";
	cin >> d;

	switch (d)
	{
	case 1:
		cout << "Сегодня день для самостоятельной работы";
		break;
	case 2: case 3:
		cout << "Сегодня 2 пары \"Программирование на Си\"";
		break;
	case 4: case 5:
		cout << "Сегодня 2 пары \"ITe\"";
		break;
	case 6: case 7:
		cout << "Сегодня выходной";
		break;
	default:
		cout << "Неверный день";
		break;
	}

	cout << endl;
	system("pause");
}