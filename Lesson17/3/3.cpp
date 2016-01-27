#include <iostream>
using namespace std;

/*
Пусть дан квадратный двумерный массив int A[n][n]. Необходимо элементам, находящимся на главной диагонали 
проходящей из левого верхнего угла в правый нижний (то есть тем элементам A[i][j], для которых i==j) 
присвоить значение 1, элементам, находящимся выше главной диагонали – значение 0,
элементам, находящимся ниже главной диагонали – значение 2.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 10, M = 10;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == j) arr[i][j] = 1;
			if (i > j) arr[i][j] = 2;
			if (i < j) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}