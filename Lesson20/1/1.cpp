#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает одномерный массив целых чисел и возвращает сумму всех чисел.

*/

int summa(int a[], int n) {
	int i, s = 0;
	for (i = 0; i<n; i++) {
		s = s + a[i];
	}
	return(s);
}


void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int i, a[5];
	for (i = 0; i<5; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << summa(a, 5);

	cout << endl;
	system("pause");
}