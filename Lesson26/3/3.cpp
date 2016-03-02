#include <iostream>
#include "functions.h"
using namespace std;

/*
Написать функцию, которая принимает указатель на массив и количество элементов и печатает все простые элементы массива. 
Простое число – это число, которое делиться ТОЛЬКО на 1 и на себя (2, 5, 7, 11 и т.д.).

*/

void print_simple(int *arr, int length);
bool is_simple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 100;
	int *arr = new int[size];
	fill_rand(arr, size, -10, 100);
	print_simple(arr, size);

	delete[] arr;
	cout << endl;
	system("pause");
}

void print_simple(int * arr, int length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (is_simple(arr[i])) cout << arr[i] << " ";
	}
}

bool is_simple(int a) {
	if (a >= -1 && a <= 1) return false;
	for (int i = 2; i < abs(a) / 2; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}