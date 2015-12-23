#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вывести на экран все трехзначные числа, у которых сумма цифр равна их произведению.

	*/

	//Код программы
	int a, sum = 0, mult = 0;
	for (int i = 100; i < 1000; i++) {
		a = i;
		sum = 0; mult = 1;
		do {
			sum += a % 10;
			mult *= a % 10;
			a /= 10;
		} while (a);
		if (sum == mult) cout << i << " ";
	}


	cout << endl;
	system("pause");
}