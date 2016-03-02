#include <iostream>
#include <math.h>
using namespace std;

/*
Вычислить, используя рекурсию, выражение

*/

double func(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы


	cout << func(6);

	cout << endl;
	system("pause");
}

double func(int a) {
	if (a > 100) {
		return sqrt(a);
	}
	else {
		return sqrt(a + (a - 4) * func(a + 1));
	}

}