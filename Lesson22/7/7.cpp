#include <iostream>
using namespace std;

/*
�������� �������, ������� �� ���� ��������  ���������� �������� (a ������� m    �   b ������� n) 
��������� ��������� ������ c[i][j]=a[i]*b[j] � ���������� ��� ������������ �������.

*/

int max(int a[], int m, int b[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	

	cout << endl;
	system("pause");
}

int max(int a[], int m, int b[], int n) {
	int result = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] * b[j] > result) {
				result = a[i] * b[j];
			}
		}
	}
	return result;
}