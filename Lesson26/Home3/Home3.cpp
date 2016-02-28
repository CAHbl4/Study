#include <iostream>
#include <windows.h>
#include "functions.h"
using namespace std;

/*
3.	�������� �������, ����������� � �������� ���������, ��������� �� ��� ������� (� � �) � ������� ��������. 
������� ���������, �������� �� ������ � ������������� ������� � � ���������� ��������� �� ������ ���������� ���������, 
���� ���������� 0 � ��������� ������.
*/

//������� ��� ���������� ������������ � ������� a
int* contains(int* a, int* b, int n, int m);

void main()
{
	setlocale(LC_CTYPE, "Rus");

	//���������� ��� ��������� �������
	HANDLE hConsole;
	WORD currentConsoleAttr = 0;
	CONSOLE_SCREEN_BUFFER_INFO csbi;

	//�������� ����� �������
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//���������� ������� ��������� �������
	if (GetConsoleScreenBufferInfo(hConsole, &csbi))
		currentConsoleAttr = csbi.wAttributes;

	//������� ��������
	int n = 100, m = 3;

	//�������� ������ ��� ��������
	int* a = new int[n];
	int* b = new int[m];

	//��������� ������� ���������� ������� �� 0 �� 3
	fill_rand(a, n, 0, 3);
	fill_rand(b, m, 0, 3);

	//�������� ��������� �� ������ ������������ � ������� a
	int* ptr = contains(a, b, n, m);

	//���� ��������� �� ������
	if (ptr)
	{
		//������� �� ����� ������ �
		cout << "������ A" << endl;
		for (int i = 0; i < n; i++)
		{
			//���� ��������� � ����� �� ������ ������������
			if (a + i == ptr)
			{
				//������ ���� �������
				SetConsoleTextAttribute(
					hConsole,
					FOREGROUND_RED | FOREGROUND_INTENSITY);
			}
			//���� ��������� �� ����� ������������
			if (a + i == ptr + m)
			{
				//������ ���� �� ���������
				SetConsoleTextAttribute(
					hConsole,
					currentConsoleAttr);
			}
			cout << a[i] << " ";
		}
		cout << endl << endl;

		//������� �� ����� ������ b
		cout << "������ B" << endl;
		print_arr(b, m);
		cout << endl;

		//������� ����� ���������
		cout << "������ B �������� ������������� ������� A, "
			<< "������ ������������ � ������� ��������� �� ������ 0x"
			<< toupper << ptr;
	}
	else
	{
		//������� �� ����� ������ �
		cout << "������ A" << endl;
		print_arr(a, n);
		cout << endl;

		//������� �� ����� ������ b
		cout << "������ B" << endl;
		print_arr(a, m);
		cout << endl;

		cout << "������ B �� �������� ������������� ������� A";
	}

	delete[] a , b;
	cout << endl;
	system("pause");
}

int* contains(int* a, int* b, int n, int m)
{
	//���� ����������� ��� ������������ �������
	bool contain;

	//��������� ���� ������ �� ������ ������� �� ����� ����� ������ �������� ������������
	for (int i = 0; i < n - m + 1; i++)
	{
		contain = true;
		//�� ������ ����� ���������� ���������� �������� a � ���������� b
		for (int j = 0; j < m; j++)
		{
			//���� �������� �� ���������
			if (*(a + i + j) != *(b + j))
			{
				//������ �� ������� ���� ������������ �� �������
				contain = false;
				//��������� ����
				break;
			}
		}
		//���� ������������ ���� ������� ���������� ��������� �� ������ ������� ������������
		if (contain) return a + i;
	}

	//���������� ������ ��������� ���� ������������ �� �������
	return nullptr;
}

