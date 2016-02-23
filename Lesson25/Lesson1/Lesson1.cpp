#include <iostream>
using namespace std;

/*
1.	Пользуясь двумя указателями на массив целых чисел, скопировать один массив в другой. 
Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.
*/
void fill_rand(int *arr, int length, int left, int right);
void copy(int *a, int *b, int size);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size = 10;
	int *a = new int[size];
	fill_rand(a, size, -10, 10);
	int *b = new int[size];


	cout << endl;
	system("pause");
}

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

void copy(int * a, int * b, int size)
{

}
