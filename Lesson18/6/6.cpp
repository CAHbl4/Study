#include <iostream>
using namespace std;

/*
В двумерном массиве int A[N][M] вычислить суммы элеметов, расположенных выше и ниже главной диагонали, результат вывести на экран.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int const N = 4, M = 4;
	int arr[N][M];

	int sumUp = 0, sumDown = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
			if (i > j) sumDown += arr[i][j];
			else if(i < j) sumUp += arr[i][j];
			cout.width(3);
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "Сумма элементов выше главной диагонали = " << sumUp << endl;
	cout << "Сумма элементов ниже главной диагонали = " << sumDown;

	cout << endl;
	system("pause");
}