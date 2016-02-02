#include <iostream>
using namespace std;

/*
4.	�������� �������, ������� � ����������� �� ������ ������������ �������� ������� ��������, 
������������, ���������, ������� ���� ����� (��� ������� ���� ����� �������� ��������������).
*/

void choice(int s);
int funcAdd(int a, int b);
int funcSub(int a, int b);
int funcMult(int a, int b);
int funcDiv(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int s;
	cout << "�������� �������:" << endl
		<< "1. ��������" << endl
		<< "2. ���������" << endl
		<< "3. ���������" << endl
		<< "4. �������" << endl
		<< "��� �����: ";
	cin >> s;
	choice(s);

	cout << endl;
	system("pause");
}

void choice(int s) {
	int a, b;
	cout << "������� ����� a, b:";
	cin >> a >> b;
		
	switch (s)
	{
	case 1:
		cout << funcAdd(a, b);
		break;
	case 2:
		cout << funcSub(a, b);
		break;
	case 3:
		cout << funcMult(a, b);
		break;
	case 4:
		if (!(b < 0)) {
			cout << funcDiv(a, b); 
		}
		else cout << "������: ������� �� ����";
		
		break;
	default:
		cout << "�������� �����.";
		break;
	}
}

int funcAdd(int a, int b) {
	return a + b;
}
int funcSub(int a, int b) {
	return a - b;
}
int funcMult(int a, int b) {
	return a * b;
}
int funcDiv(int a, int b) {
	return a / b;
}