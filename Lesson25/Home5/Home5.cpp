#include <iostream>
#include "functions.h"
using namespace std;

/*
5.	��������� ���������� �� ������ ����� �����, ����������� ����������� ����� ������� �� �������� ����� ���������. 
����������� ������ ������� �������������. ������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.
*/

enum direction{LEFT, RIGHT};

void shift(int* arr, int size, direction dir, int step);
void reverse(int* arr, int size);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

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