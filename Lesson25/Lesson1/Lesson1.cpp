#include <iostream>
using namespace std;

/*
1.	��������� ����� ����������� �� ������ ����� �����, ����������� ���� ������ � ������. 
������������ � ��������� ���������� ���������� ��� ����������� �� �������, � ����� �������� �������������.
*/
void fill_rand(int *arr, int length, int left, int right);
void copy(int *a, int *b, int size);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int size = 10;
	int *a = new int[size];
	fill_rand(a, size, -10, 10);
	int *b = new int[size];


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

void copy(int * a, int * b, int size)
{

}
