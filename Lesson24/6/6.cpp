#include <iostream>
using namespace std;

/*
������� ������ �� 10 ����� �����. ��������� ������ ��������� ������� � ��������� �� -15 �� 105. 
��������� ���������� �� ������ ����� �����, ��������� ������� �������������� ��������� �������.

*/

void fill_rand(int *arr, int length, int left, int right);
double avg(int *arr, int length);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int size = 10;
	int *arr = new int[10];
	fill_rand(arr, size, -15, 105);
	for (int i = 0; i < size; i++)
	{
		cout << *(arr + i) << " ";
	}
	cout << endl << avg(arr, size);
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

double avg(int * arr, int length)
{
	int result = 0;
	for (int i = 0; i < length; i++)
	{
		result += *(arr + i);
	}
	return double(result) / length;
}
