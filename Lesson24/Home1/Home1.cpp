#include <iostream>
using namespace std;

/*
1.	��������� ��������� � �������� �������������, ���������� ���������� �� ���� �����.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a, b;
	int *ptra = &a, *ptrb = &b;
	cout << "������� a � b: ";
	cin >> *ptra >> *ptrb;
	cout << (*ptra > *ptrb ? "� ������ b" : "b ������ a");

	cout << endl;
	system("pause");
}