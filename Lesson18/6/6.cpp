#include <iostream>
using namespace std;

/*
� ��������� ������� int A[N][M] ��������� ����� ��������, ������������� ���� � ���� ������� ���������, ��������� ������� �� �����.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int const N = 4, M = 4;
	int arr[N][M];

	int sumUp = 0, sumDown = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			arr[i][j] = rand() % 10;
			if (i > j) sumDown += arr[i][j];
			else if(i < j) sumUp += arr[i][j];
			cout.width(3);
			cout << arr[i][j];
		}
		cout << endl;
	}
	cout << "����� ��������� ���� ������� ��������� = " << sumUp << endl;
	cout << "����� ��������� ���� ������� ��������� = " << sumDown;

	cout << endl;
	system("pause");
}