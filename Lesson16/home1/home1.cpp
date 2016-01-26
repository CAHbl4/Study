#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	���������� ������������� ������ ��� ����� ������� � ������� ����������� ���� ������� �������������� 
	���� ��������� ������ ����; ����� - ���� ������ �����. ��������� ����� ������� �� ����������� � ����������� � �������� �������.
	*/

	//��� ���������

	//���������� ��������� �������
	const int N = 30;
	//������
	int arr[N];

	//��������� ������ ���������� �������
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 201 - 100;
	}

	//������� �� ����� �������� ������
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);
	cout << endl;
	
	//����� ��������� �������
	int sum = 0;

	//������� ����� ���������
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}

	//������� ��������������
	int avg = sum / N;
	cout << "������� �������������� = " << avg << endl;

	//���� ������� �������������� ������ ����
	if (avg > 0) {

		//��������� 2/3 �������
		for (int i = 0; i < N * 2/3 - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < N * 2 / 3; j++)
			{
				if (arr[j] < arr[min]) min = j;
			}
			if (min != i) {
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}

		//������ ������ ���������� �����
		for (int i = N * 2 / 3; i < N * 5 / 6; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[N - (i - N * 2 / 3) - 1];
			arr[N - (i - N * 2 / 3) - 1] = tmp;
		}
	}

	//���� ������� �������������� <= 0
	else {
		//��������� 1/3 �������
		for (int i = 0; i < N / 3 - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < N / 3; j++)
			{
				if (arr[j] < arr[min]) min = j;
			}
			if (min != i) {
				int tmp = arr[i];
				arr[i] = arr[min];
				arr[min] = tmp;
			}
		}

		//������ ������ ���������� �����
		for (int i = N / 3; i < N * 2 / 3; i++)
		{
			int tmp = arr[i];
			arr[i] = arr[N - (i - N / 3) - 1];
			arr[N - (i - N / 3) - 1] = tmp;
		}
	}

	//������� ���������
	for (int i = 0; i < N; cout << arr[i] << ' ', i++);

	cout << endl;
	system("pause");
}