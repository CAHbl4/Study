#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ��� ����� �����, � ���������� ������� �� ���

*/

int max(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	cout << max(2, 3);
	

	cout << endl;
	system("pause");
}

int max(int a, int b) {
	return (a > b ? a : b);
}