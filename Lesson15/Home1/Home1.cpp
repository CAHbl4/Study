#include <iostream>

/*
�������� ���������, ���������� ��������������� �������� ������ ������� �������� 10 ��������� � 2 ������� �������� 5 ��������� ������.
*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//���������� ��������� �������
	const int N = 10;

	//������ �������� N
	int arr[N];

	//������� N/2
	int b1[N / 2], b2[N / 2];


	cout << "�������� ������� arr[" << N << "] : ";

	//��������� ������ arr[]
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100;
		cout << arr[i] << " ";
	}

	cout << endl;

	cout << "b1["<<N/2<<"]\tb2[" << N / 2 << "]" << endl;

	//�������� �������� �� ������� arr[] � ������� ������� � ������� �� �����
	for (int i = 0; i < N / 2; i++)
	{
		b1[i] = arr[i];
		b2[i] = arr[i + N / 2];
		printf_s("%5d\t%5d\n", b1[i], b2[i]);
	}

	cout << endl;
	system("pause");
}