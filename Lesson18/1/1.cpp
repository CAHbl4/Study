#include <iostream>
using namespace std;

/*
Дан двумерный массив, заполненный целыми числами. Сформировать одномерный массив,
каждый элемент которого равен произведению четных положительных элементов соответствующего столбца.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	const int N = 3, M = 4;
	int a[N][M], b[M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			a[i][j] = rand() % 21 - 10;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(2);
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < M; i++)
	{
		int mult = 1;
		for (int j = 0; j < N; j++)
		{
			if (a[j][i] > 0) {
				mult *= a[j][i];
			}
		}
		b[i] = mult;
	}

	for (int i = 0; i < M; i++)
	{
		cout.width(2);
		cout << b[i] << " ";

	}
	cout << endl;


	cout << endl;
	system("pause");
}