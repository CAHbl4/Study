#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	2. Дан массив случайных чисел в диапазоне от -20 до +20. Необходимо найти позиции крайних отрицательных элементов 
	(самого левого отрицательного элемента и самого правого отрицательного элемента) и отсортировать элементы, находящиеся между ними.
	*/

	//Код программы

	const int N = 20;
	int arr[N];

	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 41 - 20;
	}

	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;

	int leftNeg;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0) {
			leftNeg = i;
			break;
		}
	}

	int rightNeg;
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] < 0) {
			rightNeg = i;
			break;
		}
	}

	int min;
	for (int i = leftNeg + 1; i < rightNeg; i++)
	{
		min = i;
		for (int j = i + 1; j < rightNeg; j++)
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

	cout << endl;
	system("pause");
}