#include <iostream>
using namespace std;

/*
����� ���������� �����������, ���� ����� ���� ��� ��������� ����� ��� ������. �������� ������� ������ ����� ����� �� ��������� ���������.

*/

void perf(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	perf(1, 10000);

	cout << endl;
	system("pause");
}

void perf(int a, int b) {
	int i, j, sum;
	for (i = a; i <= b; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0) sum += j;
		}
		if (sum == i) cout << i << " ";
	}
}

