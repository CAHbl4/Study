#include <iostream>
using namespace std;

/*
4.	Написать функцию, которая получает указатель на динамический массив и его размер. 
Функция должна удалить из массива все отрицательные числа и вернуть указатель на новый динамический массив.
*/

//Заполняет массив псевдо-случайными числами в заданном диапазоне
void fill_rand(int* arr, int length, int left, int right);

//Выводит элементы массива разделенные пробелами в одну линию
void print_arr(int* arr, int size);

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
		std::cout << arr[i] << " ";
	}
	cout << endl;
}