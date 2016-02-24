#include <iostream>
using namespace std;

/*
�������� ���������, ������� ��������� ��������� ���������� ����� � �������� �����. 
��������� �������� ��������� � ������ ���������� ���������� �������.

*/
int *to_arr(int a, int *sz);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a, sz;
	int *arr;
	cout << "������� �����: ";
	cin >> a;

	arr = to_arr(a, &sz);

	for (size_t i = 0; i < sz; i++)
	{
		cout << arr[i];
	}

	cout << endl;
	system("pause");
}

int *to_arr(int a, int *sz)
{
	int b = a;
	int count = 0;
	do
	{
		count++;
		b /= 2;
	} while (b);

	int *result = new int[count];
	for (size_t i = 0; i < count; i++)
	{
		result[i] = a % 2;
		a /= 2;
	}
	*sz = count;
	return result;
}