#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*������������ ������ � ���������� ���������� � �����, �� ������� ����� �������. 
	��������� ��������, � ������� ��� ����� �����.*/

	//��� ���������

	float s, t;

	cout << "������� ���������� � �����: ";
	cin >> s >> t;
	cout << "�������� = " << s / t;

	cout << endl;
	system("pause");
}