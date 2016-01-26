#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Для каждого натурального числа в промежутке от m до n вывести все делители, кроме единицы и самого числа. m и n вводятся с клавиатуры.
	*/

	//Код программы

	int m, n;
	cout << "Введите m и n: ";
	if (cin >> m >> n) {
		cout << "Список кратных чисел: " << endl;
		for (; m <= n; m++) {
			cout << m << ":";
			for (int i = 2; i <= m / 2; i++) {
				if (!(m % i)) cout << i << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "Ошибка ввода";
	}

	cout << endl;
	system("pause");
}