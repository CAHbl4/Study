#include <iostream>
using namespace std;

/*
Написать программу, которая переводит введенное десятичное число в двоичное число. 
Результат перевода сохранить в массив минимально возможного размера.

*/
int *to_arr(int a, int *sz);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int a, sz;
	int *arr;
	cout << "Введите число: ";
	cin >> a;

	arr = to_arr(a, &sz);

	for (size_t i = 0; i < sz; i++)
	{
		cout << arr[i];
	}

	cout << endl;
	system("pause");
}

int *to_arr(int a, int *sz)
{
	int b = a;
	int count = 0;
	do
	{
		count++;
		b /= 2;
	} while (b);

	int *result = new int[count];
	for (size_t i = 0; i < count; i++)
	{
		result[i] = a % 2;
		a /= 2;
	}
	*sz = count;
	return result;
}