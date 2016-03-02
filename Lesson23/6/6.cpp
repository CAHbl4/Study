#include <iostream>
using namespace std;

/*
В квадратной матрице 10x10 обменять значения элементов в каждой строке, расположенные на главной и побочной диагоналях.

*/

void swap(int *arr, int n, int m);
void fill_rand(int *arr, int n, int m, int left, int right);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 6, M = 6;
	int arr[N][M];
	fill_rand(&arr[0][0], N, M, 0, 36);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(3);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	swap(&arr[0][0], N, M);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(3);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}

void swap(int * arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int tmp = arr[i * m + i];
		arr[i * m + i] = arr[(i + 1) * m - i - 1];
		arr[(i + 1) * m - i - 1] = tmp;
	}
}

void fill_rand(int *arr, int n, int m, int left, int right)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			arr[i*m + j] = rand() % (right - left + 1) + left;
		}
	}
}