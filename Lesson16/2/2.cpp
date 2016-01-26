#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Сортировка выбором
	*/

	//Код программы

	const int N = 10;
	int arr[10];
	int min;

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 101;
	}

	for (int i = 0; i < N - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[min]) min = j;
		}
		if (min != i) {
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
		for (int i = 0; i < N; cout << arr[i] << ' ', i++);
		cout << endl;
	}

	cout << endl;
	system("pause");
}