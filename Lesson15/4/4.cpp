#include <iostream>
#include <stdio.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	const int SIZE = 10;
	int a[SIZE];
	int b[SIZE];

	int sum = 0;
	printf_s("       A        B      A*B\n");
	for (int i = 0; i < SIZE; i++)
	{
		a[i] = rand() % 100;
		b[i] = rand() % 100;
		sum += a[i] * b[i];
		printf_s("%8d %8d %8d\n", a[i], b[i], a[i] * b[i]);
	}
	cout << "Сумма произведений: " << sum;


	cout << endl;
	system("pause");
}