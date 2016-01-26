#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая по введенному пользователем числу выводит название месяца. 
	Проверять корректность ввода данных.

	*/

	//Код программы
	enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	int m;
	cout << "Введите номер месяца: ";
	if (cin >> m) {
		if (m && m <= 12) {
			switch (m)
			{
			case jan: cout << "Январь"; break;
			case feb: cout << "Февраль"; break;
			case mar: cout << "Март"; break;
			case apr: cout << "Апрель"; break;
			case may: cout << "Май"; break;
			case jun: cout << "Июнь"; break;
			case jul: cout << "Июль"; break;
			case aug: cout << "Август"; break;
			case sep: cout << "Сентябрь"; break;
			case oct: cout << "Октябрь"; break;
			case nov: cout << "Ноябрь"; break;
			case dec: cout << "Декабрь"; break;
			}
		}
		else cout << "В году 12 месяцев";
	}
	else cout << "Ошибка ввода";


	cout << endl;
	system("pause");
}