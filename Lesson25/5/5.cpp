#include <iostream>
using namespace std;

/*
�������� ���������, ������� ������� ��� ������� �� N ���������. N � �������� �������������. 
������ ��� ����������� ��������� �������, ������ ������ ����������� ��� ������������ ����� ������ ���� ��������.

*/

void fill_rand(int *arr, int length, int left, int right);
void sum(int *a, int *b, int *c, int size);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size;
	cout << "������� ������: ";
	cin >> size;

	int *a = new int[size];
	int *b = new int[size];
	int *c = new int[size];

	fill_rand(a, size, -10, 10);

	cout << "������ a: ";
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	fill_rand(b, size, -10, 10);

	cout << "������ b: ";
	for (int i = 0; i < size; i++)
	{
		cout << b[i] << " ";
	}
	cout << endl;
	
	sum(a, b, c, size);

	cout << "������ c: ";
	for (int i = 0; i < size; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;

	delete[] a, b, c;
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

void sum(int * a, int * b, int * c, int size)
{
	for (int i = 0; i < size; i++)
	{
		c[i] = a[i] + b[i];
	}
}
