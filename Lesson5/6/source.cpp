#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Пользователь вводит с клавиатуры расстояние и время, за которое нужно доехать. 
	Вычислить скорость, с которой ему нужно ехать.*/

	//Код программы

	float s, t;

	cout << "Введите расстояние и время: ";
	cin >> s >> t;
	cout << "Скорость = " << s / t;

	cout << endl;
	system("pause");
}