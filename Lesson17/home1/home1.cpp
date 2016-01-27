#include <iostream>
using namespace std;

/*

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 10, M = 20;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 100;
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

	for (int i = 0; i < N; i++)
	{
		bool sorted;
		int tmp;
		int j = 0;

		do {
			sorted = true;
			for (int k = 0; k < M - j - 1; k++) {
				if (arr[i][k] > arr[i][k + 1]) {
					tmp = arr[i][k];
					arr[i][k] = arr[i][k + 1];
					arr[i][k + 1] = tmp;
					sorted = false;
				}
			}
			j++;
		} while (!sorted);
	}

	cout << endl;

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


	cout << endl;
	system("pause");
}