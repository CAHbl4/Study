#include <iostream>
using namespace std;

/*
2.	Написать функцию для нахождения наибольшего из двух чисел.
*/

int max(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int a, b;
	cout << "Введите a, b: ";
	cin >> a >> b;

	cout << "Максимальное число " << max(a, b);

	cout << endl;
	system("pause");
}

int max(int a, int b) {
	return (a > b ? a : b);
}