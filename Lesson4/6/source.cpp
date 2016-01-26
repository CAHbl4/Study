#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*Написать программу, которая преобразует введенное с клавиатуры дробное число в денежный формат. 
	Например, число 12,5 должно быть преобразовано к виду 12руб. 50 коп.*/

	//Код программы

	float a;
	int i, d;

	cout << "Введите число: ";
	scanf_s("%g", &a);
	i = a;
	a = a - i;
	a = a * 100;
	d = a;

	cout << i << "руб. " << d << "коп." << endl;

	system("pause");
}