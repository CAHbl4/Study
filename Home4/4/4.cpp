#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ��������� ���� ���� ������ ���������� ������ � ������ ���������� ��������� �������,
	� ����� ����������������� ��������� � ������� � ��������.
	���������� ��������� ����� �� ������� ��� ���������� ������.
	*/

	//��� ���������

	float price, lenght, sum;
	int m, s;

	cout << "������� ���� �� ������ = ";
	cin >> price;
	cout << "������� ����� (���.���) = ";
	cin >> lenght;

	m = (int)lenght;
	s = round((lenght - m) * 100);
	sum = (m + s / 60.0) * price;

	cout << fixed << setprecision(2);
	cout << "�� ������������� " << m << " ���. " << s << " ���. ��������� ������ ��������� " << sum << " ���.";

	cout << endl;
	system("pause");
}