#include <iostream>
using namespace std;

/*
Написать функцию, которая по двум заданным  одномерным массивам (a размера m    и   b размера n) 
вычисляет двумерный массив c[i][j]=a[i]*b[j] и возвращает его максимальный элемент.

*/

int max(int a[], int m, int b[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	

	cout << endl;
	system("pause");
}

int max(int a[], int m, int b[], int n) {
	auto result = 0;
	for (auto i = 0; i < m; i++)
	{
		for (auto j = 0; j < n; j++)
		{
			if (a[i] * b[j] > result) {
				result = a[i] * b[j];
			}
		}
	}
	return result;
}