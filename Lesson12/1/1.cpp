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
		//for (int i = 1; i <= a; i++) {
		//	for (int j = 1; j <= a; j++) {
		//		if (a - i < j) cout << "*"; else cout << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		//for (int i = 1; i <= a; i++) {
		//	for (int j = 1; j <= a; j++) {
		//		if (a - i > j) cout << "*"; else cout << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if ( a - i < j && a - j < i) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else cout << "Ошибка ввода!";


	cout << endl;
	system("pause");
}