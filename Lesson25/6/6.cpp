#include <iostream>
using namespace std;

/*
������� ��������� ��������� �� ������, ��� ������ � ��������� �� ����������. 
����������, �������� �� ���������� ������� ������� (�.� �������� ��������� ��������� � ����� �� ������� ����� �������).
������ ������ ������� ���������� ��������.

*/

bool contain(int *arr, int size, int *a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int *arr = new int[size];
	int a;
	int *ptr_a = &a;
	int *ptr_b = &arr[size - 1];
	
	cout << contain(arr, size, ptr_a) << endl;
	cout << contain(arr, size, ptr_b) << endl;

	cout << endl;
	system("pause");
}

bool contain(int * arr, int size, int * a)
{
	for (int i = 0; i < size; i++)
	{
		if (arr + i == a)
		{
			return true;
		}
	}
	return false;
}
