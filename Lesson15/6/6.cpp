#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	const int SIZE = 10;
	int a[SIZE];
	int b1[SIZE / 2];
	int b2[SIZE / 2];

	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < SIZE / 2; i++)
	{
		b1[i] = a[SIZE / 2 - i - 1];
		b2[i] = a[SIZE - 1 - i];
		cout << b1[i] << " " << b2[i] << endl;
	}

	cout << endl;
	system("pause");
}