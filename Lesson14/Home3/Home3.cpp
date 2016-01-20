#include <iostream>

/*
� ���������� �������, ��������� �� N ������������ ����� ���������:
� ����� ������������� ���������.
� ������������ ���������, ����������� ����� min � max ����������.
� ������������ ��������� � ������� ��������.
� ����� ���������, ����������� ����� ������ � ��������� �������������� ����������.

*/

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//������ �������
	const int N = 10;

	//������
	double arr[N];

	cout << "�������� �������: ";

	//���������� ������� ���������� ���������� �� -100.00 �� 100.00
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100 + (float)(rand() % 100) / 100;
		cout << arr[i] << " ";
	}
	cout << endl;

	//����� ������������� ���������
	double sumNegative = .0;

	//��������� ��� ������������� ��������
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0) sumNegative += arr[i];
	}
	cout << "����� ������������� �����: " << sumNegative << endl;

	//������� ��������� � ���������� � ���������� ���������
	int minKey = 0, maxKey = 0;

	//������� ����������� � ������������ ��������
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < arr[minKey]) minKey = i;
		if (arr[i] > arr[maxKey]) maxKey = i;
	}
	cout << "����������� ������� arr[" << minKey << "] = " << arr[minKey] << endl;
	cout << "������������ ������� arr[" << maxKey << "] = " << arr[maxKey] << endl;

	//������������ ���������, ����������� ����� min � max ����������
	double minMaxMult = 1;
	
	//������� ������������, � ������� ���������� ��������� ���������� ������� � ������� ������
	for (int i = (minKey < maxKey ? minKey : maxKey); i <= (minKey > maxKey ? minKey : maxKey); i++) {
		minMaxMult *= arr[i];
	}
	cout << "������������ ���������, ����������� ����� min � max ����������: " << minMaxMult << endl;

	// ������������ ��������� � ������� ��������
	double evenMult = 1.;

	//������� ������������ ������ ��������� �������
	for (int i = 0; i < N; i += 2)
	{
		evenMult *= arr[i];
	}
	cout << "������������ ��������� � ������� ��������: " << evenMult << endl;

	//������� ������� � ���������� �������������� �������� �������
	int firstNegativekey, lastNegativeKey;

	//������� ������ ������� �������������� ���������
	for (int i = 0; i < N; i++)
	{
		if (arr[i] < 0) {
			firstNegativekey = i;
			break;
		}
	}
	cout << "������ ������������� ������� arr[" << firstNegativekey << "] = " << arr[firstNegativekey] << endl;

	//������� ������ ���������� �������������� �������� �������
	for (int i = N - 1; i >= 0; i--)
	{
		if (arr[i] < 0) {
			lastNegativeKey = i;
			break;
		}
	}
	cout << "��������� ������������� ������� arr[" << lastNegativeKey << "] = " << arr[lastNegativeKey] << endl;

	//����� ���������, ����������� ����� ������ � ��������� �������������� ����������
	double sumFirstLastNegative = .0;

	//������� �����
	for (int i = firstNegativekey; i <= lastNegativeKey; i++)
	{
		sumFirstLastNegative += arr[i];
	}

	cout << "����� ���������, ����������� ����� ������ � ��������� �������������� ����������: " << sumFirstLastNegative;

	cout << endl;
	system("pause");
}