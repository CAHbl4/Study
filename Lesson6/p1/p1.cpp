#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вычислить пройденное расстояние при прямолинейном равноускоренном движении по формуле S = v*t + (a*t2) / 2, где v – скорость, t – время, а – ускорение.
	*/

	//Код программы
	
	double S, v, t, a;

	cout << "Введите скорость (м/с): ";
	cin >> v;
	cout << "Введите ускорение (м/с^2): ";
	cin >> a;
	cout << "Введите время (c): ";
	cin >> t;

	S = v * t + (a*t*t) / 2;

	cout << "Вы проехали " << S << "м.";

	cout << endl;
	system("pause");
}