#include <iostream>
using namespace std;

/*
������� ����������� ������� ���������� ���(n,m) - ����������� ������ �������� ��������������� ����� ����� n � m, 
���������� �� ����������� ���(n,m) = ���(m,r), ��� r - ������� �� ������� n �� m. � �� ������� ����� ���������� ����� �������� ����������� ����� a � b.

*/

int gcd(int n, int m);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << gcd(27, 9);

	cout << endl;
	system("pause");
}

int gcd(int n, int m) {
	if (m == 0) {
		return n;
	} else {
		return gcd(m, n % m);
	}
}