#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит с клавиатуры число - программа должна показать сколько в данном числе цифр.

	*/

	//Код программы


	int a, count = 1;
	cout << "Введите число: ";
	if (cin >> a) {
		cout << "В числе " << a;
		while (a /= 10) {
			count++;
		}
		cout << " " << count << " цифр";
	}
	else {
		cout << "Ошибка ввода";
	}

	cout << endl;
	system("pause");
}