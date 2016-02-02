#include <iostream>
using namespace std;

/*
Число называется совершенным, если сумма всех его делителей равна ему самому. Напишите функцию поиска таких чисел во введенном интервале.

*/

void perf(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	perf(1, 10000);

	cout << endl;
	system("pause");
}

void perf(int a, int b) {
	int i, j, sum;
	for (i = a; i <= b; i++)
	{
		sum = 0;
		for (j = 1; j < i; j++)
		{
			if (i % j == 0) sum += j;
		}
		if (sum == i) cout << i << " ";
	}
}

