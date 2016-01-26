#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Вывести на экран фигуры заполненные звездочками. Размер стороны квадрата ввести с клавиатуры.

	*/

	//Код программы

	int a;
	cout << "Введите сторону: ";
	if (cin >> a) {
		cout << "а: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j <= 0) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "б: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j >= 0) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "в: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j <= 0 && i + j <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "г: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j >= 0 && i + j >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "д: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if ((i - j <= 0 && i + j <= a + 1) || (i - j >= 0 && i + j >= a + 1)) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "е: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (!((i - j < 0 && i + j < a + 1) || (i - j > 0 && i + j > a + 1))) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "ж: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j - i <= 0 && i + j <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "з: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j - i >= 0 && i + j >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "и: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j + i <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "к: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j + i >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else cout << "Ошибка ввода!";


	cout << endl;
	system("pause");
}