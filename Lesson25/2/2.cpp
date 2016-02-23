#include <iostream>
using namespace std;

/*
������� ������ �� 10 ����� �����. ��������� ������ ��������� ������� � ��������� �� -45 �� 45. 
��������� ���������� �� ������ ����� �����, ��������� ������� ������������� � ������������� ��������� �������.

*/

void fill_rand(int *arr, int length, int left, int right);
double percent(int *arr, int length, bool sign);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	unsigned int size = 10;
	int *arr = new int[size];
	fill_rand(arr, size, -45, 45);
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "������� �������������: " << percent(arr, size, false) << endl
		<< "������� �������������: " << percent(arr, size, true);

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

double percent(int * arr, int length, bool sign)
{
	double result = .0;
	for (int i = 0; i < length; i++)
	{
		if (sign && arr[i] > 0)
		{
			result++;
		} else if (!sign && arr[i] < 0)
		{
			result++;
		}
	}
	return result/length * 100;
}
