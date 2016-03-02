#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Дано натуральное число N. Определить самую большую цифру и ее позицию в числе (N=573863, наибольшей является цифра 8, ее позиция –четвертая слева).
	*/

	//Код программы

	int n, max = 0, pos, count = 0;
	cout << "Введите N: ";
	if (cin >> n) {
		do {
			count++;
			if (n % 10 > max) {
				max = n % 10; pos = count;
			}
			n /= 10;
		} while (n);
		cout << "Наибольшая цифра " << max << " в " << pos << " позиции";
	}
	else cout << "Ошибка ввода!";

	cout << endl;
	system("pause");
}