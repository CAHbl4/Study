#include <iostream>
using namespace std;

/*
3.	��������� ��������� � �������� �������������, �������� ������� �������� ���� ����������.
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a, *ptra = &a, b, *ptrb = &b;
	cout << "������� a � b: ";
	cin >> *ptra >> *ptrb;
	int tmp = *ptra;
	*ptra = *ptrb;
	*ptrb = tmp;
	cout << "a = " << *ptra << " b = " << *ptrb;

	cout << endl;
	system("pause");
}