#include <iostream>
using namespace std;

/*
Напишите программу вычисления функции, заданной следующим образом:
C(m,n) = C(m,n-1)+C(m-1,n-1), C(0,n)=1, m<n.
*/

int func(int m, int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << func(j, i) << " ";
		}
		cout << endl;
	}

	cout << endl;
	system("pause");
}

int func(int m, int n) {
	if (m == 0 || m == n) { return 1; }
	else {
		return func(m, n - 1) + func(m - 1, n - 1);
	}
}