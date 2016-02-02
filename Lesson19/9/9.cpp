#include <iostream>
using namespace std;

/*
Написать функцию, которая принимает три числа и показывает на экран все числа от 0 до 1000, 
которые одновременно кратны всем трем параметрам. Проиллюстрировать работу этой функции.

*/

void check(int a, int b, int c);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int a, b, c;
	cout << "Введите числа a, b, c:";
	cin >> a >> b >> c;

	cout << "Числа кратные одновременно трем числам: ";
	check(a, b, c);

	cout << endl;
	system("pause");
}

void check(int a, int b, int c) {
	for (int i = 0; i < 1000; i++)
	{
		if (!(i % a) && !(i % b) && !(i % c))
			cout << i << " ";
	}
}