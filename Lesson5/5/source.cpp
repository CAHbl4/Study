#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Пользователь вводит с клавиатуры две стороны прямоугольника.
	Посчитать площадь и периметр прямоугольника.*/

	//Код программы

	float a, b;

	cout << "Введите стороны A и B: ";
	cin >> a >> b;
	cout << "Площадь = " << a * b << ", периметр = " << (a + b) * 2;

	cout << endl;
	system("pause");
}