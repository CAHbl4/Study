#include <iostream>
using namespace std;

/*
��� ������ �����, ���������� ������ � ���� � ������� �� ���� ����� � ������� ����������.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	const int SZ = 5;
	int arr[5];
	int *ptr = arr;
	for (size_t i = 0; i < SZ; i++)
	{
		*(ptr + i) = i;
		cout << *(ptr + i) << " " ;
	}

	cout << endl;
	system("pause");
}