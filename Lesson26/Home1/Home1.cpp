#include <iostream>
#include "functions.h"
using namespace std;

/*
1.	�������� �������, ������� �������� ��������� �� ������ � ��� ������, � ���������� ����� � ������������ ��� ��������� � ���� ����������-����������.
*/

void sum_mult(int *arr, int size, int *sum, int *mult);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int *arr = (int*) malloc(sizeof(int) * size);
	
	fill_rand(arr, size, 1, 10);
	print_arr(arr, size);

	int sum, mult;
	sum_mult(arr, size, &sum, &mult);

	cout << "����� = " << sum
		<< ", ������������ = " << mult;

	free(arr);
	cout << endl;
	system("pause");
}

void sum_mult(int * arr, int size, int * sum, int * mult)
{
	*sum = 0;
	*mult = 1;
	for (int i = 0; i < size; i++)
	{
		*sum += arr[i];
		*mult *= arr[i];
	}
}
