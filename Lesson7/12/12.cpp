#include <iostream>

using namespace std;

float exp(int x, int y);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая возводит число в степень. Учесть отрицательные степени.

	*/

	//Код программы

	int x, y;
	cout << "Введите число: ";
	if (cin >> x) {
		cout << "Введите степень: ";
		if (cin >> y) {
			cout << x << "^" << y << " = " << exp(x, y);
		}
		else {
			cout << "Ошибка ввода" << endl;
			system("pause");
			return;
		}
	}
	else {
		cout << "Ошибка ввода" << endl;
		system("pause");
		return;
	}

	cout << endl;
	system("pause");
}

float exp(int x, int y) {
	int i;
	float result = 1.0;
	if (y < 0) {
		for (i = 0; i < -y; i++) {
			result *= x;
		}
		result = 1 / result;
	}
	else if (y > 0) {
		for (i = 0; i < y; i++) {
			result *= x;
		}
	}
	return result;
}