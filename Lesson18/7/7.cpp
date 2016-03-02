#include <iostream>
using namespace std;

/*
В двумерном массиве int A[n][m] четные строки отсортировать по возрастанию, а нечетные по убыванию.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int const N = 5, M = 6;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	
	bool sorted;
	int tmp;
	for (int i = 0; i < N; i++)
	{
		int k = 0;
		do
		{
			sorted = true;
			for (int j = 0; j < M - k - 1; j++)
			{
				if (i % 2) {
					if (arr[i][j] < arr[i][j + 1]) {
						tmp = arr[i][j];
						arr[i][j] = arr[i][j + 1];
						arr[i][j + 1] = tmp;
						sorted = false;
					}
				} else
					if (arr[i][j] > arr[i][j + 1]) {
						tmp = arr[i][j];
						arr[i][j] = arr[i][j + 1];
						arr[i][j + 1] = tmp;
						sorted = false;
					}
			}
			k++;
		} while (!sorted);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}