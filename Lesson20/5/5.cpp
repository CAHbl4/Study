#include <iostream>
using namespace std;

/*
Напишите функцию, которая определяет количество  элементов передаваемого массива, 
которые меньше определенного числа, это число тоже передается в функцию.

*/

int numLesserThan(int a[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] < x) {
			count++;
		}
	}
	return count;
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
	cout << numLesserThan(a, 5, 3);

	cout << endl;
	system("pause");
}