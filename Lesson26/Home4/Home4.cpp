#include <iostream>
#include "functions.h"
using namespace std;

/*
4.	Ќаписать функцию, котора€ получает указатель на динамический массив и его размер. 
‘ункци€ должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.
*/

void delete_negative(int **arr, int *size);

void main() {
	setlocale(LC_CTYPE, "Rus");
	
	int size = 10;
	int *arr = new int[size];

	fill_rand(arr, size, -10, 10);
	print_arr(arr, size);
	cout << endl;

	delete_negative(&arr, &size);

	print_arr(arr, size);

	delete[] arr;
	cout << endl;
	system("pause");
}

void delete_negative(int **arr, int *size)
{
	int new_size = *size;
	for (int i = 0; i < *size; i++)
	{
 		if (*(*arr + i) < 0) new_size--;
	}

	int *result = new int[new_size];
	int j = 0;
	for (int i = 0; i < *size; i++)
	{
		if (*(*arr + i) >= 0)
		{
			result[j] = *(*arr + i);
			j++;
		}
	}

	delete[] *arr;
	*size = new_size;
	*arr = result;
}
