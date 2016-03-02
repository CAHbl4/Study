#include <iostream>
using namespace std;

/*
Даны числа n и m. Создайте массив int A[n][m] и заполните его следующей змейкой (ниже приведен пример для n=4 и m=6):
			 0   1   2   3   4   5
			11  10   9   8   7   6
			12  13  14  15  16  17
			23  22  21  20  19  18

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы


	int const N = 4, M = 6;
	int arr[N][M];
	int t = 0;

	for (int i = 0; i < N; i++)
	{
		if (i % 2) {
			for (int j = M - 1; j >= 0 ; j--)
			{ 
				arr[i][j] = t++;
			}
		}
		else {
			for (int j = 0; j < M; j++)
			{
				arr[i][j] = t++;
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
	system("pause");
}