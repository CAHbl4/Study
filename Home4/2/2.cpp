﻿#include <iostream>
#include <math.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая преобразует введенное с клавиатуры дробное число в денежный формат.
	Например, число 12,5 должно быть преобразовано к виду 12руб. 50 коп.
	*/

	//Код программы

	double a;
	int i, d;

	cout << "Введите число: ";
	cin >> a;

	i = (int)a;
	a = (a - i) * 100;
	d = round(a); //Костыльно-ориентированное программирование, без этого введенное 6.6 будет 6.59

	cout << i << "руб. " << d << "коп.";

	cout << endl;
	system("pause");
}