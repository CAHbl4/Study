#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вывести на экран кубы чисел от A до B.

	*/

	//Код программы

	int a, b;

	cout << "Введите A и B: ";
	if (cin >> a >> b) {
		cout << "A\tA^3" << endl;
		for (; a <= b; a++) {
			cout << a << "\t" << a * a * a << endl;
		}
	}
	else {
		cout << "Ошибка ввода";
	}



	cout << endl;
	system("pause");
}