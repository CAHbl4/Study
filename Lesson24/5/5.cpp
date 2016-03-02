#include <iostream>
using namespace std;

/*
Создать массив из 10 целых чисел. Заполнить массив случайным образом в диапазоне от -44 до 76. 
Пользуясь указателем на массив целых чисел, посчитать произведение элементов массива.

*/

void fill_rand(int *arr, int length, int left, int right);
long long mult(int *arr, int length);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int size = 10;
	int *arr = new int[size];
	fill_rand(arr, size, -44, 76);
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl << mult(arr, size);
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

long long mult(int * arr, int length)
{
	int result = 1;
	for (int i = 0; i < length; i++)
	{
		result *= *(arr + i);
	}
	return result;
}
