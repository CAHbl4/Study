
#include <iostream>
using namespace std;

/*
Дан двумерный массив. Переставить его строки так, чтобы первый столбец был упорядочен по возрастанию.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	const int N = 5, M = 6;
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
	do {
		sorted = true;
		for (int i = 0; i < N - 1; i++)
		{
			if (arr[i][0] > arr[i + 1][0]) {
				for (int k = 0; k < M; k++)
				{
					tmp = arr[i][k];
					arr[i][k] = arr[i + 1][k];
					arr[i + 1][k] = tmp;
				}
				sorted = false;
			}
		}

	} while (!sorted);

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