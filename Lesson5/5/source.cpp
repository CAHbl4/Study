#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*������������ ������ � ���������� ��� ������� ��������������.
	��������� ������� � �������� ��������������.*/

	//��� ���������

	float a, b;

	cout << "������� ������� A � B: ";
	cin >> a >> b;
	cout << "������� = " << a * b << ", �������� = " << (a + b) * 2;

	cout << endl;
	system("pause");
}