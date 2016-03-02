#include <iostream>
#include "functions.h"
using namespace std;

/*
Написать функцию, которая принимает указатель на массив, количество элементов массива и новый элемент и 
выполняет вставку нового элемента после последнего отрицательного элемента в массиве.
Если такого элемента в массиве нет, то вставляет в конец массива.

*/

int *add_el(int *arr, int *length, int el);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 20;
	int *arr = new int[size];
	fill_rand(arr, size, -10, 20);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	arr = add_el(arr, &size, 10);

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	
	cout << endl;
	system("pause");
}

int *add_el(int *arr, int *length, int el)
{
	int *result = new int[*length + 1];
	int j;
	bool added = false;
	for (int i = *length - 1; i >= 0; i--)
	{
		if (arr[i] < 0)
		{
			for (j = 0; j <= i; j++)
			{
				result[j] = arr[j];
			}
			result[j] = el;
			for (j += 1; j < *length + 1; j++)
			{
				result[j] = arr[j - 1];
			}
			added = true;
			break;
		}
	}
	if (!added)
	{
		for (j = 0; j < *length; j++)
		{
			result[j] = arr[j];
		}
		result[j] = el;
	}
	delete[] arr;
	*length += 1;
	return result;
}
