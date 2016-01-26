#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Необходимо написать программу, которая принимает от пользователя номер месяца и сообщает время года, к которому этот месяц относится.
	Задача должна быть решена с использованием конструкции switch.
	*/

	//Код программы

	enum month { jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
	int m;
	cout << "Введите номер месяца: ";
	if (cin >> m) {
		if (m > 0 && m <= 12) {
			switch (m)
			{
			case dec: case jan: case feb: 
				cout << "Зима";
				break;
			case mar: case apr: case may:
				cout << "Весна";
				break;
			case jun: case jul: case aug:
				cout << "Лето";
				break;
			case sep: case oct: case nov:
				cout << "Осень";
				break;
			}

		}
		else cout << "В году 12 месяцев";
	}
	else cout << "Ошибка ввода";


	cout << endl;
	system("pause");
}