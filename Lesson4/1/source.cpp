#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << "data type\t" << "size" << endl;
	cout << "bool=\t\t" << sizeof(bool) << endl;
	cout << "char=\t\t" << sizeof(char) << endl;
	cout << "short int=\t" << sizeof(short int) << endl;
	cout << "int=\t\t" << sizeof(int) << endl;
	cout << "long int=\t" << sizeof(long int) << endl;
	cout << "float=\t\t" << sizeof(float) << endl;
	cout << "double=\t\t" << sizeof(double) << endl;

	system("pause");
}