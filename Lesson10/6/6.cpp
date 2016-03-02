#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь с клавиатуры последовательно вводит целые числа. Как только пользователь ввел 0, необходимо показать на экран среднее арифметическое всех введенных чисел.

	*/

	//Код программы

	int a, sum = 0, count = 0;

	while (1) {
		if (cin >> a) {
			if (a == 0) break;
			sum += a;
			count++;
		}
		else {
			cin.clear();
			cin.sync();
			cout << "Ошибка ввода" << endl;
		}
	}

	cout << "Среднее арифметическое введенных чисел = " << (double)sum / count;

	cout << endl;
	system("pause");
}