#include <iostream>
using namespace std;

/*
Функция принимает указатель на массив, его размер и указатель на переменную. 
Определить, является ли переменная ячейкой массива (т.е значение указателя совпадает с одним из адресов ячеек массива).
Функця должна вернуть логическое значение.

*/

bool contain(int *arr, int size, int *a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int *arr = new int[size];
	int a;
	int *ptr_a = &a;
	int *ptr_b = &arr[size - 1];
	
	cout << contain(arr, size, ptr_a) << endl;
	cout << contain(arr, size, ptr_b) << endl;

	cout << endl;
	system("pause");
}

bool contain(int * arr, int size, int * a)
{
	for (int i = 0; i < size; i++)
	{
		if (arr + i == a)
		{
			return true;
		}
	}
	return false;
}
