#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая по выбору пользователя возводит введенное им число в степень от нулевой до седьмой включительно. Проверять корректность ввода данных.

	*/

	//Код программы

	double x, result = 1;
	int y;

	cout << "Введите число: ";
	if (cin >> x) {
		cout << "Введите степень (0 - 7): ";
		if (cin >> y && y >= 0 && y <= 7) {
			cout << x << "^" << y << "=";
			while (y) {
				result *= x;
				y--;
			}
			cout << result;
		}
		else cout << "Неверный ввод";
	}
	else cout << "Неверный ввод";



	cout << endl;
	system("pause");
}

