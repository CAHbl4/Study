#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	�������� ���������, � ������� �������� ��� �������� � � Y � ���� �������� (+, �, /, *). 
	��������� ��������� Z � ����������� �� �����. 
	������������� ������� �� ��������� �������� ���� ��������, � ����� �� ���� Y=0 ��� �������. 
	������������ ����������� ������������ ���������� ��� ������������ ��������� (�.�. ��������� ����). � �������� ������� ����������� ���������� ������� �0�.
	*/

	//��� ���������

	float a, b;
	char op;

	cout << "����� ���������� � �����-�����-������-�����������-2015" << endl;
	while (1) {
		cout << "������� �������� ��� 0 ��� ������. ��������� �������� + - * /, ��� �����: ";
		if (cin >> op) {
			switch (op)
			{
			case '+': case '-': case '*': case '/':
				cout << "������� ��������: ";
				if (cin >> a >> b) {
					switch (op)
					{
					case '+':
						cout << a << " + " << b << " = " << a + b << endl;
						break;
					case '-':
						cout << a << " - " << b << " = " << a - b << endl;
						break;
					case '*':
						cout << a << " * " << b << " = " << a * b << endl;
						break;
					case '/':
						if (b) cout << a << " / " << b << " = " << a / b << endl;
						else cout << "������. ������� �� 0!" << endl;
						break;
					}
				}
				else {
					cin.clear();
					cin.sync();
					cout << "������ �����!" << endl;
				}
				break;
			case '0':
				return;
			default:
				cout << "�������� ��������!" << endl;
				break;
			}
		}
		else {
			cin.clear();
			cin.sync();
			cout << "������ �����!" << endl;
		}
	}

	cout << endl;
	system("pause");
}