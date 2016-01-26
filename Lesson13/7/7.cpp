#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Зарплата менеджера составляет 200$ + процент от продаж, продажи до 500$ - 3%, от 500 до 1000 – 5%, свыше 1000 – 8%.
	Пользователь вводит с клавиатуры уровень продаж для трех менеджеров. 
	Определить их зарплату, определить лучшего менеджера, начислить ему премию 200$, вывести итоги на экран.

	*/

	//Код программы

	int arr[3];

	for (int i = 0; i < 3; i++) {
		cout << "Введите уровень продаж для " << i << " менеджера: ";
		if (cin >> arr[i]);
		else { cout << "Ошибка ввода!"; system("pause"); return; }
	}
	
	int max = 0;
	for (int i = 0; i < 3; i++) {
		if (arr[i] > arr[max]) max = i;
	}

	for (int i = 0; i < 3; i++) {
		if (arr[i] < 500) arr[i] = arr[i] / 100 * 3;
		else if (arr[i] >= 500 && arr[i] < 1000) arr[i] = arr[i] / 100 * 5;
		else arr[i] = arr[i] / 100 * 8;
		arr[i] += 200;
		if (max == i) arr[i] += 200;
	}

	for (int i = 1; i <= 3; i++) {
		cout << "Зарплата менеджера " << i << ": " << arr[i - 1] << endl;
	}

	cout << endl;
	system("pause");
}