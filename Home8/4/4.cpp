#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая с использованием  конструкции switch-case определяет,
	каким днем (Рабочий день, Суббота, Воскресенье) является введенный номер дня недели.

	*/

	//Код программы
	enum days { mon = 1, tue, wed, thu, fri, sat, sun };
	int d;
	cout << "Введите номер дня: ";
	if (cin >> d) {
		if (d && d <= 7) {
			switch (d)
			{
			case mon: case tue: case wed: case thu: case fri: 
				cout << "Рабочий день"; break;
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