#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая по введенному пользователем числу выводит название дня недели.
	Проверять корректность ввода данных.

	*/

	//Код программы
	enum days { mon = 1, tue, wed, thu, fri, sat, sun};
	int d;
	cout << "Введите номер дня: ";
	if (cin >> d) {
		if (d && d <= 7) {
			switch (d)
			{
			case mon: cout << "Понедельник"; break;
			case tue: cout << "Вторник"; break;
			case wed: cout << "Среда"; break;
			case thu: cout << "Четверг"; break;
			case fri: cout << "Пятница"; break;
			case sat: cout << "Суббота"; break;
			case sun: cout << "Воскресенье"; break;
			}
		}
		else cout << "В неделе 7 дней";
	}
	else cout << "Ошибка ввода";



	cout << endl;
	system("pause");
}