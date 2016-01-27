#include <iostream>
using namespace std;

/*
Дано число n. Создайте массив int A[n][n], и заполните его по следующему правилу:
Числа на диагонали, идущей из правого верхнего в левый нижний угол равны 1.
Числа, стоящие выше этой диагонали, равны 0.
Числа, стоящие ниже этой диагонали, равны 2.    
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 10;
	int arr[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i + j == N - 1) arr[i][j] = 1;
			if (i + j > N -1) arr[i][j] = 2;
			if (i + j < N -1) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}