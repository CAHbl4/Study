#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ��� ����� � ���������� �� ����� ��� ����� �� 0 �� 1000, 
������� ������������ ������ ���� ���� ����������. ����������������� ������ ���� �������.

*/

void check(int a, int b, int c);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a, b, c;
	cout << "������� ����� a, b, c:";
	cin >> a >> b >> c;

	cout << "����� ������� ������������ ���� ������: ";
	check(a, b, c);

	cout << endl;
	system("pause");
}

void check(int a, int b, int c) {
	for (int i = 0; i < 1000; i++)
	{
		if (!(i % a) && !(i % b) && !(i % c))
			cout << i << " ";
	}
}