#include <iostream>
using namespace std;

/*
1.	Написать функцию, определяющую среднее арифметическое элементов передаваемого ей массива.
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

	int const N = 5;
	int i, a[N];
	for (i = 0; i < N; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;
	cout << avg(a, N);

	cout << endl;
	system("pause");
}