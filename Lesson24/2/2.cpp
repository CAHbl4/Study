#include <iostream>
using namespace std;

/*

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int var = 123; // инициализация переменной var числом 123
	int *ptrvar = &var; // указатель на переменную var
	int **ptr_ptrvar = &ptrvar; //указатель на указатель на переменную var
	int ***ptr_ptr_ptrvar = &ptr_ptrvar;
	cout << " var\t\t= " << var << endl;
	cout << " *ptrvar\t= " << *ptrvar << endl;
	cout << " **ptr_ptrvar   = " << **ptr_ptrvar << endl;
	cout << " ***ptr_ptrvar  = " << ***ptr_ptr_ptrvar << endl;

	system("pause");
}