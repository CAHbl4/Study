#include <iostream>

using namespace std;

unsigned long long fib(int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	����� ��������� � ��� �������� �������� ������������������ 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, �, � ������� ������ ����������� ����� ����� ����� ���� ����������.
	������� �� ����� ��� ����� ���������, ��������� �� n ���������.

	*/

	//��� ���������

	int n;
	cout << "������� n: ";
	if (cin >> n) {
		cout << fib(n);
	}
	else cout << "������ �����";

	cout << endl;
	system("pause");
}

unsigned long long fib(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}