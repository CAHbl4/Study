#include <iostream>
using namespace std;

/*
Написать функцию, которая меняет порядок элементов передаваемого массива на обратный.

*/
void revert(int a[], int n) {
	for (int i = 0; i < n / 2; i++)
	{
		int tmp = a[i];
		a[i] = a[n - i -1];
		a[n - i - 1] = tmp;
	}
}

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	int const N = 6;
	int i, a[N];
	for (i = 0; i < N; i++) {
		a[i] = rand() % 10;
		cout << a[i] << " ";
	}
	cout << endl;

	revert(a, N);
	for (int i = 0; i < N; i++)
	{
		cout << a[i] << " ";
	}

	cout << endl;
	system("pause");
}