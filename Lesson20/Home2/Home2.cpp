#include <iostream>
using namespace std;

/*
2.	�������� �������, ������������ ���������� �������������, ������������� � ������� ��������� ������������� �� �������.
*/

struct num {
	int negative;
	int positive;
	int zero;
};

num func(int a[], int n) {
	num result;
	result.negative = 0;
	result.positive = 0;
	result.zero = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > 0) {
			result.positive++;
		}
		else if (a[i] < 0) {
			result.negative++;
		}
		else
		{
			result.zero++;
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
		a[i] = rand() % 21 - 10;
		cout << a[i] << " ";
	}
	cout << endl;

	num x = func(a, i);

	cout << "��������� ������ 0: " << x.positive << endl;
	cout << "��������� ������ 0: " << x.negative << endl;
	cout << "��������� ������ 0: " << x.zero << endl;

	cout << endl;
	system("pause");
}