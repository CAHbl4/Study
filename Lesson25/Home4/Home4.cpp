#include <iostream>
#include "functions.h"
using namespace std;

/*
4.	Пользуясь указателем на массив целых чисел, найти минимальный и максимальный элемент массива. 
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

void find_min_max(int* arr, int size, int* min, int* max);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int* arr = new int[size];
	int* min = new int;
	int* max = new int;

	fill_rand(arr, size, 0, 100);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	find_min_max(arr, size, min, max);

	cout << "MIN = " << *min << endl;
	cout << "MAX = " << *max << endl;

	delete[] arr;
	delete min, max;
	cout << endl;
	system("pause");
}

void find_min_max(int* arr, int size, int* min, int* max)
{
	*min = *max = *arr;
	for (int i = 0; i < size; i++)
	{
		if (*(arr + i) < *min) *min = *(arr + i);
		if (*(arr + i) > *max) *max = *(arr + i);
	}
}

