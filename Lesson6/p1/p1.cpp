#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ���������� ���������� ��� ������������� ��������������� �������� �� ������� S = v*t + (a*t2) / 2, ��� v � ��������, t � �����, � � ���������.
	*/

	//��� ���������
	
	double S, v, t, a;

	cout << "������� �������� (�/�): ";
	cin >> v;
	cout << "������� ��������� (�/�^2): ";
	cin >> a;
	cout << "������� ����� (c): ";
	cin >> t;

	S = v * t + (a*t*t) / 2;

	cout << "�� �������� " << S << "�.";

	cout << endl;
	system("pause");
}