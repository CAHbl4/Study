#include <iostream>

using namespace std;

unsigned long long int fact(int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Факториал числа представляет собой произведение всех натуральных чисел от 1 до этого числа включительно.
	Например, факториал числа 7 выглядит так: 7! = 1 * 2 * 3 * 4 * 5 * 6 * 7; 0! = 1.
	Вычислить факториал числа, введенного пользователем.

	*/

	//Код программы
	unsigned long long int f;
	int n;
	cout << "Введите число: ";
	if (cin >> n) {

		//Вычисляем функцией
		f = fact(n);
		cout << "Рекурсивная функция:" << endl
			<< "Факториал: " << f << endl;

		//Вычисляем циклом
		f = 1;
		while (n) {
			f = f * n;
			n--;
		};
		cout << "Цикл:" << endl
			<< "Факториал: " << f << endl;
	}
	else cout << "Ошибка ввода!";

	cout << endl;
	system("pause");
}

unsigned long long int fact(int n) {
	if (n) return n * fact(n - 1);
	else return 1;
}