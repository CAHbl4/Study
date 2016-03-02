#include <iostream>
using namespace std;

/*
6.	Написать функцию, которая проверяет, является ли переданное ей число простым? 
Число называется простым, если оно делится без остатка только на себя и на единицу.
*/

bool isSimple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int a;

	cout << "Введите число: ";
	cin >> a;

	cout << "Число " << a << (isSimple(a) ? " простое" : " не простое");

	cout << endl;
	system("pause");
}

bool isSimple(int a) {
	for (int i = 2; i < a - 1; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}