#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ����� ������������ ����� � ��������� ����� �� �����
������ ���� ���� ����� ��������� ���� ����(���������� �����). ������� ���������� ������,
���� ����� ���������� (����� �����) � ����, ���� �� ���������� (����� �� �����).

*/

bool luckyTicket(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int a;

	cout << "������� 6-�� ������� �����: ";
	cin >> a;

	cout << "����� " << (luckyTicket(a) ? "����������" : "�� ����������");

	cout << endl;
	system("pause");
}

bool luckyTicket(int a) {
	int sumRight = 0, sumLeft = 0;
	if (a > 99999 && a < 1000000) {
		for (int i = 0; i < 6; i++)
		{
			if (i < 3) {
				sumRight += a % 10;
			}
			else {
				sumLeft += a % 10;
			}
			a /= 10;
		}
		return sumRight == sumLeft;
	}
	else return false;
}