#include <iostream>
using namespace std;

/*
6.	�������� �������, ������� ���������, �������� �� ���������� �� ����� �������? 
����� ���������� �������, ���� ��� ������� ��� ������� ������ �� ���� � �� �������.
*/

bool isSimple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a;

	cout << "������� �����: ";
	cin >> a;

	cout << "����� " << a << (isSimple(a) ? " �������" : " �� �������");

	cout << endl;
	system("pause");
}

bool isSimple(int a) {
	for (int i = 2; i < a - 1; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}