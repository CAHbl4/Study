#include <iostream>
using namespace std;

/*
5.	�������� �������, ��������� �� ����� ������������� � ������� N � ������� K.
*/

void rect(int width, int height);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������
	int width, height;

	cout << "������� ������: ";
	cin >> width;
	cout << "������� ������: ";
	cin >> height;

	rect(width, height);

	cout << endl;
	system("pause");
}

void rect(int width, int height) {
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
}