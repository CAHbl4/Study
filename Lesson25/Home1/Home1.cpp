﻿#include <iostream>
using namespace std;

/*
1.	Пользуясь двумя указателями на массив целых чисел, скопировать один массив в другой. 
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length , int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

void copy(int* a, int* b, int size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int* a = new int[size];
	int* b = new int[size];

	fill_rand(a, size, 0, 10);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	copy(a, b, size);
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	delete[] a , b;
	cout << endl;
	system("pause");
}

void copy(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(b + i) = *(a + i);
	}
}

void fill_rand(int* arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

void print_arr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}