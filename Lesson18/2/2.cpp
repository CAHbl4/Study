#include <iostream>
using namespace std;

/*
Заполнить массив размером 7?7 по правилу:
1 1 1 1 1 1 1
0 1 1 1 1 1 0
0 0 1 1 1 0 0
0 0 0 1 0 0 0
0 0 1 0 1 0 0
0 1 0 0 0 1 0
1 0 0 0 0 0 1

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	const int N = 7;
	int arr[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			
			if ((i == j) || (i + j == N - 1)||( (i < j && j < N - 1 - i))) arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;

	cout << endl;
	system("pause");
}