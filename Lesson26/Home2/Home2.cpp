#include <iostream>
using namespace std;

/*
2.	Написать функцию, которая получает указатель на массив и его размер, и возвращает количество отрицательных, положительных и нулевых элементов массива.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

void func(int *arr, int size, int *negative, int *zero, int *positive);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int *arr = new int[size];
	
	fill_rand(arr, size, -10, 10);
	print_arr(arr, size);

	int negative, zero, positive;
	func(arr, size, &negative, &zero, &positive);

	cout << "Количество элементов: " << endl
		<< "Отрицательных = " << negative << endl
		<< "Положительных = " << positive << endl
		<< "Нулевых = " << zero << endl;

	delete[] arr;

	cout << endl;
	system("pause");
}

void func(int * arr, int size, int * negative, int * zero, int * positive)
{
	*negative = *zero = *positive = 0;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0) (*negative)++;
		else if (arr[i] > 0) (*positive)++;
		else (*zero)++;
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