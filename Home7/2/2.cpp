#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	����������� ������� ����������� ��� ������� �������������� ��������. ��������� ������������ ����� ������.

	*/

	//��� ���������

	double a, b;
	char op;
	cout << "������� ��������� � ������� a + b, ��������� �������� + - * /: ";
	if (cin >> a && cin >> op && cin >> b) {
		switch (op)
		{
		case '+':
			cout << a << op << b << '=' << a + b;
			break;
		case '-':
			cout << a << op << b << '=' << a - b;
			break;
		case '*':
			cout << a << op << b << '=' << a * b;
			break;
		case '/':
			if (b)		cout << a << op << b << '=' << a / b;
			else cout << "������� �� ����";
			break;
		default:
			printf("�������� ���������");
			break;
		}
	}
	else cout << "�������� ���������";
	cout << endl;
	system("pause");
}