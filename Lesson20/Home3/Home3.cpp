#include <iostream>
using namespace std;

/*
3.	�������� �������, ������������ ���������� ������� ����� � ������������ �� �������.
*/

int simple(int a[], int n) {
	int result = 0;
	bool simple;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 1) {
			simple = true;
			for (int j = 2; j < a[i]; j++)
			{

				if (a[i] % j == 0) {
					simple = false;
					break;
				}
			}
			if (simple) {
				result++;
			}
		}
	}
	return result;
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int const N = 10;
	int i, a[N];
	for (i = 0; i < N; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	
	cout << "���������� ������� �����: " << simple(a, N);

	cout << endl;
	system("pause");
}