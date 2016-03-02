#include <iostream>
using namespace std;

/*
Даны два двумерных массива. Перемножить их как матрицы. Результат записать в третий массив.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 3, M = 4, Q = 5;
	int a[N][M], b[M][Q], c[N][Q];

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[j][i] = rand() % 10;
		}
		for (int j = 0; j < Q; j++)
		{
			b[i][j] = rand() % 10;
		}
	}
	int tmp;
	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			tmp = 0;
			for (int k = 0; k < M; k++)
			{
				tmp += a[i][k] * b[k][j];
			}
			c[i][j] = tmp;
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
		for (int j = 0; j < Q; j++)
		{
			cout.width(2);
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < Q; j++)
		{
			cout.width(2);
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << endl;
	system("pause");
}