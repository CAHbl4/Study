#include <iostream>
using namespace std;

/*
�������� �������, ������� ��������� ������ � ���������� ��������� � ���������� ������� �������������� ���� ��������� �������. 
���������� ������ ��� � ������, ��� � � ������������� ���������. ���������� �������� ������� ��� ������ �������� ������ �����.
*/

double avg(int a[], int n);
double avg(double a[], int n);

void printarr(int a[], int n);
void printarr(double a[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	

	cout << endl;
	system("pause");
}

double avg(int a[], int n) {
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += a[i];
	}

	return result / n;
}

double avg(double a[], int n) {
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		result += a[i];
	}

	return result / n;
}

void printarr(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}

void printarr(double a[], int n) {
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
}