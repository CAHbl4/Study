#include <iostream>
#include "functions.h"
using namespace std;

/*
2.	��������� ���������� �� ������ ����� �����, �������� ������� ���������� ���������  ������� �� ���������������. 
������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.
*/

void reverse(int* arr, int size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

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

