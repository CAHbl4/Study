#include <iostream>
using namespace std;

/*
2.	�������� ������� ��� ���������� ����������� �� ���� �����.
*/

int max(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a, b;
	cout << "������� a, b: ";
	cin >> a >> b;

	cout << "������������ ����� " << max(a, b);

	cout << endl;
	system("pause");
}

int max(int a, int b) {
	return (a > b ? a : b);
}