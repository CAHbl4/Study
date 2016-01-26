#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Реализовать простой калькулятор для четырех арифметических операций. Проверять корректность ввода данных.

	*/

	//Код программы

	double a, b;
	char op;
	cout << "Введите выражение в формате a + b, Доступные действия + - * /: ";
	if (cin >> a && cin >> op && cin >> b) {
		switch (op)
		{
		case '+':
			cout << a << op << b << '=' << a + b;
			break;
		case '-':
			cout << a << op << b << '=' << a - b;
			break;
		case '*':
			cout << a << op << b << '=' << a * b;
			break;
		case '/':
			if (b)		cout << a << op << b << '=' << a / b;
			else cout << "Деление на ноль";
			break;
		default:
			printf("Неверное выражение");
			break;
		}
	}
	else cout << "Неверное выражение";
	cout << endl;
	system("pause");
}