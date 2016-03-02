#include <iostream>

/*
Написать программу, копирующую последовательно элементы одного массива размером 10 элементов в 2 массива размером 5 элементов каждый.
*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Количество элементов массива
	const int N = 10;

	//Массив размером N
	int arr[N];

	//Массивы N/2
	int b1[N / 2], b2[N / 2];


	cout << "Элементы массива arr[" << N << "] : ";

	//Заполняем массив arr[]
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100;
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "b1["<<N/2<<"]\tb2[" << N / 2 << "]" << endl;

	//Копируем элементы из массива arr[] в меньшие массивы и выводим на экран
	for (int i = 0; i < N / 2; i++)
	{
		b1[i] = arr[i];
		b2[i] = arr[i + N / 2];
		printf_s("%5d\t%5d\n", b1[i], b2[i]);
	}

	cout << endl;
	system("pause");
}