#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���������� ������������� ����������� �� �������� ^. ������ ������ � ����������. ��������� �� ������ ���� ������ �� 8 ������� (���������).


	*/

	//��� ���������

	int height = 0;
	cout << "������� ������: ";
	cin >> height;
	for (int i = 0; i < height; i++)
	{
		cout << "\t";
		for (int j = height - i; j <= height; j++)
		{
			cout << '^';
		}
		cout << endl;
	}


	cout << endl;
	system("pause");
}