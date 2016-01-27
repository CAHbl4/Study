#include <iostream>
using namespace std;

/*
����� ��� ���������� ��������� ������ int A[n][n]. ���������� ���������, ����������� �� ������� ��������� 
���������� �� ������ �������� ���� � ������ ������ (�� ���� ��� ��������� A[i][j], ��� ������� i==j) 
��������� �������� 1, ���������, ����������� ���� ������� ��������蠖 �������� 0,
���������, ����������� ���� ������� ��������蠖 �������� 2.

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int const N = 10, M = 10;
	int arr[N][M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (i == j) arr[i][j] = 1;
			if (i > j) arr[i][j] = 2;
			if (i < j) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}