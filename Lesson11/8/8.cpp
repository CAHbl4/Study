#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Ввести число. Если количество его разрядов меньше пяти, то вывести его на экран, 
	дописав нули перед числом так, чтобы в итоге получилось пять знаков.
	Если количество разрядов больше пяти, то вывести только первые пять разрядов. Если число пятизначное, то вывести его как есть.
	*/

	//Код программы

	long a;

	cout << "Введите число: ";
	if (cin >> a) {
		int b = a ,i = 0;

		for (; b; i++, b /= 10);
		while (i - 5) {
			if (i - 5 < 0) { cout << '0'; i++; }
			else { a /= 10; i--; }
		}
		cout << a;

	}
	else cout << "Ошибка ввода!";


	cout << endl;
	system("pause");
}