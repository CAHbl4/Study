﻿#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, которая преобразует введенное пользователем количество дней в количество полных недель и оставшихся дней. 
	Например, пользователь ввел 17 дней, программа должна вывести на экран 2 недели и 3 дня.
	*/

	//Код программы

	int d;

	cout << "Введите количество дней : ";
	cin >> d;
	cout << d << " д. = " << d / 7 << " нед. и " << d % 7 << " д.";

	cout << endl;
	system("pause");
}