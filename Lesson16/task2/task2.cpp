#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Заполнить массив из 10 элементов случайными числами в интервале [0..100] и отсортировать первую половину по возрастанию, а вторую – по убыванию.

	*/

	//Код программы

	const int N = 10;
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 101;
	}
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;
	for (int i = 0; i < N / 2; i++)
	{
		for (int j = 0; j < (N / 2) - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			if (arr[j + N / 2] < arr[j + N / 2 + 1]) {
				int tmp = arr[j + N / 2];
				arr[j + N / 2] = arr[j + N / 2 + 1];
				arr[j + N / 2 + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;

	cout << endl;
	system("pause");
}