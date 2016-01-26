#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит текущий год и год его рождения. Посчитать, сколько лет пользователю.

	*/

	//Код программы

	int current_year, birth_year;

	cout << "Введите текущий год: ";
	cin >> current_year;
	if (current_year < 1) cout << "В то время компьютеров не было";
	else {
		cout << "Введите год рождения: ";
		cin >> birth_year;
		if (birth_year > current_year) cout << "Вы еще не родились";
		else cout << "Вам " << current_year - birth_year << " лет";
	}

	cout << endl;
	system("pause");
}