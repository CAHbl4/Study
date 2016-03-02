#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает массив и количество элементов и возвращает среднее арифметическое всех элементов массива.

*/

double avg(int a[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
	}
	return (double)sum / n;
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int i, a[5];
	for (i = 0; i < 5; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << avg(a, 5);

	cout << endl;
	system("pause");
}