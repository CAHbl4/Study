#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Выполнить сортировку только четных элементов массива (нечетные элементы остаются на своих местах)

	*/

	//Код программы

	const int N = 10;
	int arr[10];
	
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 101;
	}

	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;

	int min;

	for (int i = 0; i < N; i += 2)
	{
		min = i;
		int j = 0;
		for (j = j + i; j < N - 1 ; j += 2)
		{
			if (arr[j] < arr[min]) min = j;
		}
		if (min != i) {
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}

	for (int i = 0; i < N; cout << arr[i] << ' ', i++);

	cout << endl;
	system("pause");
}