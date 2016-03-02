#include <iostream>
using namespace std;

/*
Написать функцию, которая заполняет массив случайными числами в диапазоне, указанном пользователем. 
Функция должна принимать два аргумента - начало диапазона и его конец, при этом ничего не возвращать. 
Вывод значений элементов массива должен происходить в основной ветке программы.

*/

void fill_rand(int arr[], int n, int left, int right);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int const N = 10;
	int arr[N];
	fill_rand(arr, N, -10, 20);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	system("pause");
}

void fill_rand(int arr[], int n, int left, int right)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (right - left + 1) + left;
	}
}
