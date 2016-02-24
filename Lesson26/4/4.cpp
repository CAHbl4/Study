#include <iostream>
#include "functions.h"
using namespace std;

/*
�������� �������, ������� ��������� ��������� �� ������ � ���������� ���������.
������� ������� ������, ������ �� ���� �������� ������� 20. ���������� ��������� �� ����� ������, ���������� ������ �������� ������� 20.

*/

int *del_m(int *arr, int *length, int m);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 20;
	int *arr = new int[size];
	fill_rand(arr, size, 0, 60);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	arr = del_m(arr, &size, 20);

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	system("pause");
}

int *del_m(int *arr, int *length, int m)
{
	int count = 0;
	for (size_t i = 0; i < *length; i++)
	{
		if (arr[i] < m)
			count++;
	}
	int *result = new int[count];
	int j = 0;
	for (size_t i = 0; i < *length; i++)
	{
		if (arr[i] < m)
		{
			result[j] = arr[i];
			j++;
		}
	}
	delete[] arr;
	*length = count;
	return result;
}
