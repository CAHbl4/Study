#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ������ ���������� ������� � ���������, ��������� �������������. 
������� ������ ��������� ��� ��������� - ������ ��������� � ��� �����, ��� ���� ������ �� ����������. 
����� �������� ��������� ������� ������ ����������� � �������� ����� ���������.

*/

void fill_rand(int arr[], int n, int left, int right);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int const N = 10;
	int arr[N];
	fill_rand(arr, N, -10, 20);

	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
	system("pause");
}

void fill_rand(int arr[], int n, int left, int right)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (right - left + 1) + left;
	}
}
