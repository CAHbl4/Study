#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает массив и количество элементов и возвращает среднее арифметическое всех элементов массива. 
Обеспечить работу как с целыми, так и с вещественными массивами. Аналогично напишите функцию для печати массивов разных типов.
*/

double avg(int a[], int n);
double avg(double a[], int n);

void printarr(int a[], int n);
void printarr(double a[], int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	

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