#include <iostream>


using namespace std;

FILE *stream;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������� ����� ����������� �����. ���� ��� ������ - �������� ��� �������, ���� �������� - ������� �� 3, �������� 1 � �������� �������.
	�������� ��� �������� � ����� ���������� ������. �������� ������, ��� ���������� �� ������ ������� ����� ���� ��� ������ �� ������� 1.
	��������� �������� ��� ���� ����� �� 20 �� 30. ������� �����, ��� ������� �������� �����.

	*/

	//��� ���������
	errno_t err;
	int n = 0, m = 100;

	err = fopen_s(&stream, "out.csv", "w+");
	if (err)
	{
		cout << "������ ��� �������� �����." << endl;
		system("pause");
		return;
	}


	for (; n <= m; n++) {
		int k = n;
		int count = 0;
		do {
			if (k % 2) k = (k * 3 + 1) / 2;
			else k /= 2;
			count++;
		} while (k > 1);
		if (k == 1) {
			fprintf_s(stream, "%d,%d\n", n, count);
		}
	}

	fclose(stream);
	system("pause");
}