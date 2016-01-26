#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь вводит  целую часть, числитель и знаменатель для простой дроби. Перевести эту дробь в десятичную.

	*/

	//Код программы

	int i, n, d;

	cout << "Введите целую часть, числитель и знаменатель: ";
	cin >> i >> n >> d;
	if (n > d) cout << "Числитель должен быть меньше знаменателя";
	else cout << i << " " << n << "/" << d << " = " << (double)n / d + i;

	cout << endl;
	system("pause");
}