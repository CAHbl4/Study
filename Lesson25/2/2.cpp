#include <iostream>
using namespace std;

/*
Создать массив из 10 целых чисел. Заполнить массив случайным образом в диапазоне от -45 до 45. 
Пользуясь указателем на массив целых чисел, посчитать процент положительных и отрицательных элементов массива.

*/

void fill_rand(int *arr, int length, int left, int right);
double percent(int *arr, int length, bool sign);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	unsigned int size = 10;
	int *arr = new int[size];
	fill_rand(arr, size, -45, 45);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Процент отрицательных: " << percent(arr, size, false) << endl
		<< "Процент положительных: " << percent(arr, size, true);

	delete[] arr;
	cout << endl;
	system("pause");
}

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

double percent(int * arr, int length, bool sign)
{
	double result = .0;
	for (int i = 0; i < length; i++)
	{
		if (sign && arr[i] > 0)
		{
			result++;
		} else if (!sign && arr[i] < 0)
		{
			result++;
		}
	}
	return result/length * 100;
}
