#include <iostream>
#include "functions.h"
using namespace std;

/*
Написать функцию, которая получает указатель на динамический массив и его размер. 
Функция должна удалить из массива все простые числа и вернуть указатель на новый динамический массив.

*/

int *del_s(int *arr, int *length);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 20;
	int *arr = new int[size];
	fill_rand(arr, size, 0, 60);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	arr = del_s(arr, &size);

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}


	cout << endl;
	system("pause");
}

int *del_s(int *arr, int *length)
{
	int count = 0;
	for (size_t i = 0; i < *length; i++)
	{
		if (!is_simple(arr[i]))
			count++;
	}
	int *result = new int[count];
	int j = 0;
	for (size_t i = 0; i < *length; i++)
	{
		if (!is_simple(arr[i]))
		{
			result[j] = arr[i];
			j++;
		}
	}
	delete[] arr;
	*length = count;
	return result;
}
