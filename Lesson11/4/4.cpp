#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу, в которой вводятся два операнда Х и Y и знак операции (+, –, /, *). 
	Вычислить результат Z в зависимости от знака. 
	Предусмотреть реакции на возможный неверный знак операции, а также на ввод Y=0 при делении. 
	Организовать возможность многократных вычислений без перезагрузки программы (т.е. построить цикл). В качестве символа прекращения вычислений принять ‘0’.
	*/

	//Код программы

	float a, b;
	char op;

	cout << "Добро пожаловать в Супер-Опять-Писать-Калькулятор-2015" << endl;
	while (1) {
		cout << "Введите операцию или 0 для выхода. Возможные операции + - * /, ваш выбор: ";
		if (cin >> op) {
			switch (op)
			{
			case '+': case '-': case '*': case '/':
				cout << "Введите операнды: ";
				if (cin >> a >> b) {
					switch (op)
					{
					case '+':
						cout << a << " + " << b << " = " << a + b << endl;
						break;
					case '-':
						cout << a << " - " << b << " = " << a - b << endl;
						break;
					case '*':
						cout << a << " * " << b << " = " << a * b << endl;
						break;
					case '/':
						if (b) cout << a << " / " << b << " = " << a / b << endl;
						else cout << "Ошибка. Деление на 0!" << endl;
						break;
					}
				}
				else {
					cin.clear();
					cin.sync();
					cout << "Ошибка ввода!" << endl;
				}
				break;
			case '0':
				return;
			default:
				cout << "Неверная операция!" << endl;
				break;
			}
		}
		else {
			cin.clear();
			cin.sync();
			cout << "Ошибка ввода!" << endl;
		}
	}

	cout << endl;
	system("pause");
}