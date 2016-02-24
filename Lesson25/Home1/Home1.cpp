#include <iostream>
#include "functions.h"
using namespace std;

/*
1.	��������� ����� ����������� �� ������ ����� �����, ����������� ���� ������ � ������. 
������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.
*/

void copy(int* a, int* b, int size);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int* a = new int[size];
	int* b = new int[size];

	fill_rand(a, size, 0, 10);
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
	copy(a, b, size);
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;

	delete[] a , b;
	cout << endl;
	system("pause");
}

void copy(int* a, int* b, int size)
{
	for (int i = 0; i < size; i++)
	{
		*(b + i) = *(a + i);
	}
}

