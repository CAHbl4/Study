#include <iostream>
using namespace std;

/*
7.	�������� �������, ����������� ��������� ����������� �� �����.
*/

unsigned long long fact(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int a;
	cout << "������� �����: ";
	cin >> a;
	cout << "!" << a << " = " << fact(a);

	cout << endl;
	system("pause");
}

unsigned long long fact(int a) {
	unsigned long long result = 1;
	for (int i = 1; i <= a; i++)
	{
		result *= i;
	}
	return result;
}