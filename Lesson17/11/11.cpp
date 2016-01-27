#include <iostream>
using namespace std;

/*
Состязания - 4. Будем считать, что победитель определяется по лучшему результату.
Определите количество участников состязаний, которые разделили первое место, то есть определите количество строк в массиве, которые содержат значение, равное наибольшему.
Вход                   Выход
4 3                    2
1 2 3
4 5 6
6 2 5
2 3 4

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 4, M = 3;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
		}
	}

	int max = 0;
	int count = 1;

	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > max) {
				max = arr[i][j];
				count = 1;
			}
			else if (arr[i][j] == max) {
				count++;
			}
		}

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

	cout << endl << count;


	cout << endl;
	system("pause");
}