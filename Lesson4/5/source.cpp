﻿#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Пользователь вводит с клавиатуры время в секундах. 
	Необходимо написать программу, которая переведет введенные пользователем секунды  в часы, минуты, секунды и выводит их на экран.*/

	//Код программы

	int s, h, m;
	cout << "Введите время в секундах: ";
	cin >> s;
	
	m = s / 60;
	h = m / 60;
	m = m - h * 60;
	s = s - h * 60 * 60 - m * 60;
	cout << h << ':' << m << ':' << s << endl;

	system("pause");
}