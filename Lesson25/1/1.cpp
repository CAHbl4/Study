#include <iostream>
using namespace std;

/*
�������� �������, ������� ������ ������� �������� ���� ����������.

*/

void swap(int *a, int *b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a, b;
	cin >> a >> b;
	swap(a, b);
	cout << "a = " << a << ", b = " << b;

	cout << endl;
	system("pause");
}

void swap(int * a, int * b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
