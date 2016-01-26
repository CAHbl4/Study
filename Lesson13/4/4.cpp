#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит два числа. Определить, равны ли эти числа, и если нет, вывести их на экран в порядке возрастания.

	*/

	//Код программы

	int a, b;
	cout << "Введите числа: ";
	if (cin >> a >> b) {
		if (a == b) { cout << "Числа равны"; }
		else if (a > b){
			cout << a << " " << b;
		}
		else {
			cout << b << " " << a;
		}
	}
	else { cout << "Ошибка ввода!"; }

	cout << endl;
	system("pause");
}