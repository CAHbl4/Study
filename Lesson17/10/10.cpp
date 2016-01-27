#include <iostream>
using namespace std;

/*
Состязания - 3. Будем считать, что побеждает спортсмен, у которого максимален наилучший бросок. 
Если таких несколько, то из них побеждает тот, у которого наилучшая сумма результатов по всем попыткам. 
Если и таких несколько, победителем считается спортсмен с минимальным номером. 

Определите номер победителя соревнований.
Вход                   Выход
4 3                    2
8 8 8
5 9 3
9 4 7
6 6 2

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
	int n = 0, m = 0;
	for (int i = 0; i < N; i++)
	{
		int sum = 0;
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] > max) {
				max = arr[i][j];
				n = i;
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

	cout << endl << n;

	cout << endl;
	system("pause");
}