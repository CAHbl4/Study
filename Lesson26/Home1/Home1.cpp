#include <iostream>
#include "functions.h"
using namespace std;

/*
1.	Написать функцию, которая получает указатель на массив и его размер, и возвращает сумму и произведение его элементов в двух параметрах-указателях.
*/

void sum_mult(int *arr, int size, int *sum, int *mult);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int *arr = (int*) malloc(sizeof(int) * size);
	
	fill_rand(arr, size, 1, 10);
	print_arr(arr, size);

	int sum, mult;
	sum_mult(arr, size, &sum, &mult);

	cout << "Сумма = " << sum
		<< ", произведение = " << mult;

	free(arr);
	cout << endl;
	system("pause");
}

void sum_mult(int * arr, int size, int * sum, int * mult)
{
	*sum = 0;
	*mult = 1;
	for (int i = 0; i < size; i++)
	{
		*sum += arr[i];
		*mult *= arr[i];
	}
}
