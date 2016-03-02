#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит число. Определить, положительное это число, отрицательное или равно нулю.
	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		if (a > 0) { cout << "Число положительное"; }
		else if (a == 0) { cout << "Число равно 0"; }
		else if (a < 0) { cout << "Число отрицательное"; }
			
	}
	else { cout << "Ошибка ввода!"; }

	cout << endl;
	system("pause");
}