#include <iostream>
using namespace std;

/*
2.	Пользуясь указателем на массив целых чисел, изменить порядок следования элементов  массива на противоположный. 
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

void reverse(int* arr, int size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int* arr = new int[size];
	fill_rand(arr, size, 0, 10);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	reverse(arr, size);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;
	cout << endl;
	system("pause");
}

void reverse(int* arr, int size)
{
	int tmp;
	for (int i = 0; i < size / 2; i++)
	{
		tmp = *(arr + i);
		*(arr + i) = *(arr + size - 1 - i);
		*(arr + size - 1 - i) = tmp;
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