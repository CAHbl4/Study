#include <iostream>
using namespace std;

/*
Если p и q - простые числа и q = p+2, то они называются простыми сдвоенными числами или “близнецами” (twin primes). 
Например, 3 и 5 - такие простые числа. Распечатать все простые числа близнецы, меньшие N.

*/

bool isSimple(int a);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы
	const int N = 100;

	for (int i = 1; i < N - 2; i++)
	{
		if (isSimple(i) && isSimple(i + 2)) {
			cout << i << " " << i + 2 << endl;
		}
	}
	
	cout << endl;
	system("pause");
}

bool isSimple(int a) {
	for (int i = 2; i < a / 2; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}