#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, подсчитывающую количество четных и нечетных цифр в числе.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";

	if (cin >> a) {
		int odd = 0 , even = 0;
		do {
			if (a % 10 % 2) even++;
			else odd++;
			a /= 10;
		} while (a);
		cout << "Четных: " << odd << endl << "Нечетных: " << even;
	}
	else cout << "Ошибка ввода!";


	cout << endl;
	system("pause");
}