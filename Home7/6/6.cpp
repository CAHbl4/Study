#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая принимает от пользователя целое число в диапазоне от 0 до 100000 и выводит это число по цифрам через пробел. 
	Решение задачи реализовать с помощью конструкции switch

	*/

	//Код программы

	int a, b, count = 0;
	cout << "Введите число от 0 до 100000: ";

	if (cin >> a && a > 0 && a < 100000) {
		b = a;
		while (b) {
			count++;
			b /= 10;
		}
		switch (count) {
		case 5:	cout << a / 10000 << " "; a %= 10000;
		case 4: cout << a / 1000 << " "; a %= 1000;
		case 3: cout << a / 100 << " "; a %= 100;
		case 2: cout << a / 10 << " "; a %= 10;
		case 1: cout << a;
		default : break;
		}
	}
	else cout << "Ошибка ввода";

	cout << endl;
	system("pause");
}