#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������  ����� �����, ��������� � ����������� ��� ������� �����. ��������� ��� ����� � ����������.

	*/

	//��� ���������

	int i, n, d;

	cout << "������� ����� �����, ��������� � �����������: ";
	cin >> i >> n >> d;
	if (n > d) cout << "��������� ������ ���� ������ �����������";
	else cout << i << " " << n << "/" << d << " = " << (double)n / d + i;

	cout << endl;
	system("pause");
}