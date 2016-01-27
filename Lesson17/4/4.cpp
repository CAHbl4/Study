#include <iostream>
using namespace std;

/*
���� ����� n. �������� ������ int A[n][n], � ��������� ��� �� ���������� �������:
����� �� ���������, ������ �� ������� �������� � ����� ������ ���� ����� 1.
�����, ������� ���� ���� ���������, ����� 0.
�����, ������� ���� ���� ���������, ����� 2. ���
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int const N = 10;
	int arr[N][N];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i + j == N - 1) arr[i][j] = 1;
			if (i + j > N -1) arr[i][j] = 2;
			if (i + j < N -1) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}