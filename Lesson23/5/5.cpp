#include <iostream>
using namespace std;

/*
Посчитать суммы каждой строки и каждого столбца матрицы. Вывести суммы строк в конце каждой строки, а суммы столбцов под соответствующими столбцами.
*/

void fill_rand(int *arr, int n, int m, int left, int right);
int sum_row(int arr[], int n);
int sum_col(int *arr, int i, int n, int m);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 3, M = 4;
	int arr[N][M];
	fill_rand(&arr[0][0], N, M, -9, 9);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(3);
			cout << arr[i][j] << " ";
		}
		cout << "|"
			<< sum_row(&arr[i][0], M)
			<< endl;
	}
	for (size_t i = 0; i < M; i++)
	{
		cout << "----";
	}
	cout << endl;
	for (size_t i = 0; i < M; i++)
	{
		cout.width(3);
		cout << sum_col(&arr[0][0], i, N, M) << " ";
	}

	cout << endl;
	system("pause");
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

int sum_col(int * arr, int col_i, int n, int m)
{
	int result = 0;
	for (int i = col_i; i < n * m; i = i + m)
	{
		result += arr[i];
	}
	return result;
}

int sum_row(int arr[], int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += arr[i];
	}
	return result;
}