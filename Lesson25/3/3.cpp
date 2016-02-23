#include <iostream>
using namespace std;

/*
������� ������ �� 10 ����� �����. ��������� ������ ��������� �������. 
��������� ���������� �� ������ ����� �����, ��������� ����� ��������� ������� � ��������� ��������.

*/
void fill_rand(int *arr, int length, int left, int right);
int sum_odd(int *arr, int length);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int *arr = new int[size];

	fill_rand(arr, size, -10, 10);
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "����� ��������� � �������� ��������: " << sum_odd(arr, size) << endl;

	delete[] arr;
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

int sum_odd(int * arr, int length)
{
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		if (i % 2)
		{
			result += arr[i];
		}
	}
	return result;
}
