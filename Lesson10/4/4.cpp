#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вывести на экран все числа от нуля до введенного пользователем числа.

	*/

	//Код программы

	int a;
	cout << "Введите число: ";
	if (cin >> a) {
		for (int i = 0; i <= a; i++)
			cout << i << " ";
	}
	else {
		cout << "Ошибка ввода";
		return;
	}



	cout << endl;
	system("pause");
}