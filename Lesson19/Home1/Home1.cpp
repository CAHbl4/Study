#include <iostream>
using namespace std;

/*
1.	Написать функцию, которая возвращает куб числа.
*/

int cube(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int a;
	cout << "Введите число: ";
	cin >> a;

	cout << "Куб числа = " << cube(a);

	cout << endl;
	system("pause");
}

int cube(int a) {
	return a * a * a;
}