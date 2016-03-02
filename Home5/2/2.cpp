#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");
	streamsize def_precision = cout.precision();
	streamsize def_width = cout.width();
	char def_fill = cout.fill();

	/*
	Пользователь вводит с клавиатуры дробное число. Округлить его до двух знаков после запятой и вывести на экран. 
	Предусмотреть округление по правилам, чтобы число 12,341 округлялось до 12,34, а число 12,349 – до 12,35.
	*/

	//Код программы

	double f, d;

	cout << "Введите число: ";
	cin >> f;

	cout << "Выводим округленное через <math.h>: " << round(f * 100) / 100 << endl;

	cout << "Выводим округленное через через формат cout: " << fixed << setprecision(2) << f << endl;
	cout << resetiosflags(ios_base::fixed) << setprecision(def_precision);		//Сбрасываем установленные флаги

	d = f - (int)f;													//Получаем дробную часть
	d = d < 0 ? (int)(-d * 1000) : (int)(d * 1000);				//Откидываем знак и получаем 3 цифры после запятой
	d = (int)d % 10 < 5 ? (int)d / 10 : (int)d / 10 + 1;		//Округляем до 2х знаков

	cout << "Выводим странным способом: " << (int)f << "." << setw(2) << setfill('0') << d << endl;		//Продам велосипед недорого
	cout << setw(def_width) << setfill(def_fill);			//Сбрасываем установленные флаги

	f = f < 0 ? (int)f - d / 100.0 : (int)f + d / 100.0;		//"Собираем" число заново с учетом знака

	cout << "Выводим нормальным способом: " << f << endl;;

	cout << endl;
	system("pause");
}