#include <iostream>

using namespace std;

unsigned long long int fact(int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ����� ������������ ����� ������������ ���� ����������� ����� �� 1 �� ����� ����� ������������.
	��������, ��������� ����� 7 �������� ���: 7! = 1 * 2 * 3 * 4 * 5 * 6 * 7; 0! = 1.
	��������� ��������� �����, ���������� �������������.

	*/

	//��� ���������
	unsigned long long int f;
	int n;
	cout << "������� �����: ";
	if (cin >> n) {

		//��������� ��������
		f = fact(n);
		cout << "����������� �������:" << endl
			<< "���������: " << f << endl;

		//��������� ������
		f = 1;
		while (n) {
			f = f * n;
			n--;
		};
		cout << "����:" << endl
			<< "���������: " << f << endl;
	}
	else cout << "������ �����!";

	cout << endl;
	system("pause");
}

unsigned long long int fact(int n) {
	if (n) return n * fact(n - 1);
	else return 1;
}