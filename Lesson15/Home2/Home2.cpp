#include <iostream>

/*
�������� ���������, ������� ��������� ������������ ����� ���� �������� � ��������� ������� � ������ ������.
*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//������ ��������
	const int N = 10;

	//������� � �������
	int a[N], b[N];

	//�������������� ������
	int c[N];

	printf_s("a[%d]\tb[%d]\tc[%d]\n", N, N, N);

	//��������� ������� a, b ���������� ������� � ����������� ����� � ������ c, ������� ���������� �� �����
	for (int i = 0; i < N; i++)
	{
		a[i] = rand() % 201 - 100;
		b[i] = rand() % 201 - 100;
		c[i] = a[i] + b[i];
		printf_s("%5d\t%5d\t%5d\n", a[i], b[i], c[i]);
	}


	cout << endl;
	system("pause");
}