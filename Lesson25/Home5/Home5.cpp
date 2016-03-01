#include <iostream>
using namespace std;

/*
5.	Пользуясь указателем на массив целых чисел, осуществить циклический сдвиг массива на заданное число элементов. 
Направление сдвига задаётся пользователем. Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/

enum direction{LEFT, RIGHT};

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

void shift(int* arr, int size, direction dir, int step);
void reverse(int* arr, int size);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int *arr = new int[size];

	fill_rand(arr, size, 0, 10);
	print_arr(arr, size);

	shift(arr, size, RIGHT, 3);

	print_arr(arr, size);

	delete[] arr;
	cout << endl;
	system("pause");
}

void shift(int * arr, int size, direction dir, int step)
{
	switch (dir)
	{
	case RIGHT:
		reverse(arr, size - step);
		reverse(arr + size - step, step);
		reverse(arr, size);
		break;
	case LEFT:
		reverse(arr, step);
		reverse(arr + step, size - step);
		reverse(arr, size);
		break;
	}
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