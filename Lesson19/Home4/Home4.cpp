#include <iostream>
using namespace std;

/*
4.	Написать функцию, которая в зависимости от выбора пользователя вызывает функции сложения, 
произведения, вычитания, деления двух чисел (эти функции тоже нужно написать самостоятельно).
*/

void choice(int s);
int funcAdd(int a, int b);
int funcSub(int a, int b);
int funcMult(int a, int b);
int funcDiv(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int s;
	cout << "Выберите оперцию:" << endl
		<< "1. Сложение" << endl
		<< "2. Вычитание" << endl
		<< "3. Умножение" << endl
		<< "4. Деление" << endl
		<< "Ваш выбор: ";
	cin >> s;
	choice(s);

	cout << endl;
	system("pause");
}

void choice(int s) {
	int a, b;
	cout << "Введите числа a, b:";
	cin >> a >> b;
		
	switch (s)
	{
	case 1:
		cout << funcAdd(a, b);
		break;
	case 2:
		cout << funcSub(a, b);
		break;
	case 3:
		cout << funcMult(a, b);
		break;
	case 4:
		if (!(b < 0)) {
			cout << funcDiv(a, b); 
		}
		else cout << "Ошибка: деление на ноль";
		
		break;
	default:
		cout << "Неверный выбор.";
		break;
	}
}

int funcAdd(int a, int b) {
	return a + b;
}
int funcSub(int a, int b) {
	return a - b;
}
int funcMult(int a, int b) {
	return a * b;
}
int funcDiv(int a, int b) {
	return a / b;
}