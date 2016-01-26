#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	const int SIZE = 10;
	int a[SIZE];
	int b[SIZE / 2];

	cout << "A[]: ";
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}
	cout << endl;

	cout << "B[]: ";
	for (int i = 0; i < SIZE / 2; i++)
	{
		b[i] = a[i] * a[SIZE - 1 - i];
		cout << b[i] << " ";
	}

	cout << endl;
	system("pause");
}