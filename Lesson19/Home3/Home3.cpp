#include <iostream>
using namespace std;

/*
3.	Написать функцию, которая возвращает истину, если передаваемое значение положительное и ложь, если отрицательное.
*/

bool isPositive(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int a;
	cout << "Введите число: ";
	cin >> a;

	cout << "Число " << a << (isPositive(a) ? " положительное" : " отрицательное");

	cout << endl;
	system("pause");
}

bool isPositive(int a) {
	return a >= 0;
}