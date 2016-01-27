#include <iostream>
using namespace std;

/*

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
			arr[i][j] = (i + 1) * (j + 1);
		}
	}

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