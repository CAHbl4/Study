#include <iostream>
using namespace std;

/*

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//��� ���������

	int var = 123; // ������������� ���������� var ������ 123
	int *ptrvar = &var; // ��������� �� ���������� var
	int **ptr_ptrvar = &ptrvar; //��������� �� ��������� �� ���������� var
	int ***ptr_ptr_ptrvar = &ptr_ptrvar;
	cout << " var\t\t= " << var << endl;
	cout << " *ptrvar\t= " << *ptrvar << endl;
	cout << " **ptr_ptrvar�� = " << **ptr_ptrvar << endl;
	cout << " ***ptr_ptrvar� = " << ***ptr_ptr_ptrvar << endl;

	system("pause");
}