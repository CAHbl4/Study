#include <iostream>
using namespace std;

/*
2.	��������� ��������� � �������� �������������, ���������� ���� �����, ��������� � ����������.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a, *ptra = &a;
	cout << "������� ����� �����: ";
	cin >> *ptra;
	cout << (*ptra >= 0 ? "����� �������������" : "����� �������������");

	cout << endl;
	system("pause");
}