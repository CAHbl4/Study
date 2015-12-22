#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая показывает все числа, которым кратно число, введенное с клавиатуры.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		cout << "Список кратных чисел: ";
		for (int i = 2; i <= a / 2; i++) {
			if (!(a % i)) cout << i << " ";
		}
	}
	else {                                                                                                                                                                         
		cout << "Ошибка ввода";
	}

	cout << endl;
	system("pause");
}