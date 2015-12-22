#include <iostream>
#include <ctime>

using namespace std;

unsigned long long int fib_r(int n);
unsigned long long int fib_n(int n);


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
		unsigned long long int f;
		clock_t c_start, c_end;

		c_start = clock();
		f = fib_r(n);
		c_end = clock();

		cout << "�������� ����� ��������. ���������������� ���������." << endl;
		cout << "f = " << f << endl;
		cout << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";

		c_start = clock();
		f = fib_n(n);
		c_end = clock();

		cout << "�������� ��� ��������. �������� ���������." << endl;
		cout << "f = " << f << endl;
		cout << "CPU time used: " << 1000.0 * (c_end - c_start) / CLOCKS_PER_SEC << " ms\n";


	}
	else cout << "������ �����";

	cout << endl;
	system("pause");
}

unsigned long long int fib_r(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	return fib_r(n - 1) + fib_r(n - 2);
}

unsigned long long int fib_n(int n) {
	if (n <= 0) return 0;
	else if (n == 1) return 1;
	else {
		long value0 = 0;
		long value1 = 1;
		long value2 = 1;
		for (int i = 0; i < n - 1; i++) {
			value2 = value0 + value1;
			value0 = value1;
			value1 = value2;
		}
		return value2;
	}
}