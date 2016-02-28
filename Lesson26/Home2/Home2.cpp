#include <iostream>
#include "functions.h"
using namespace std;

/*
2.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ���������� �������������, ������������� � ������� ��������� �������.
*/

void func(int *arr, int size, int *negative, int *zero, int *positive);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int *arr = new int[size];
	
	fill_rand(arr, size, -10, 10);
	print_arr(arr, size);

	int negative, zero, positive;
	func(arr, size, &negative, &zero, &positive);

	cout << "���������� ���������: " << endl
		<< "������������� = " << negative << endl
		<< "������������� = " << positive << endl
		<< "������� = " << zero << endl;

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
