#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ���������� ������ ����� ����� � ���������� �������� ������������� ����� � ���� �������.

*/

int max(int a[], int n) {
	int max = a[0];
	for (int i = 1; i < n; i++)
	{
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int i, a[5];
	for (i = 0; i<5; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << max(a, 5);

	cout << endl;
	system("pause");
}