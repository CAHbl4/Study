#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Дана последовательность чисел, состоящих только из цифр 0 и 5, в порядке возрастания: 0 5 50 55 500 505 5000 5005 5050 и так далее. Найти k-ое по порядку в этой последовательности число.
	Алгоритм

	*/

	//Код программы

	int k;

	cout << "Введите число: ";
	if (cin >> k) {
		unsigned long long a = 0, b;
		int i = 0;
		while (i <= k - 1) {
			a += 5;
			b = a;
			do {
				if (b % 10 != 5 && b % 10 != 0) break;
				b /= 10;
				if (b == 0) i++;
			} while (b > 0);
		}
		cout << a;
	}
	else {
		cout << "Ошибка ввода";
	}



	cout << endl;
	system("pause");
}