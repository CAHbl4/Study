#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Пользователь с клавиатуры вводит 5 оценок студента. Определить, допущен ли студент к экзамену. Студент получает допуск, если его средний балл 4 балла и выше.

	*/

	//Код программы

	int arr[5];

	cout << "Введите оценки: ";
	for (int i = 0; i < 5; i++) {
		if (cin >> arr[i]);
		else { cout << "Ошибка ввода!"; system("pause"); return; }
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		sum += arr[i];
	}
	if (sum / 5 >= 4) { cout << "Есть допуск"; }
	else { cout << "Нет допуска"; }

	cout << endl;
	system("pause");
}