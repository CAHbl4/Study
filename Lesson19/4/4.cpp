#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ��� ����� �����, � ���������� ������� �� ���.

*/

int max(int a, int b, int c);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << max(2, 3, 4);

	cout << endl;
	system("pause");
}

int max(int a, int b, int c) {
	if (a > b && a > c) return a;
	else if (b > c) return b;
	else return c;
}