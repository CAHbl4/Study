#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ���������� ������ ����� ����� � ���������� ������������ ���� �����.

*/

int mult(int a[], int n) {
	int i, s = 1;
	for (i = 0; i<n; i++) {
		s *= a[i];
	}
	return(s);
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int i, a[5];
	for (i = 0; i<5; i++) {
		a[i] = rand() % 10;
	}
	cout << mult(a, 5);

	cout << endl;
	system("pause");
}