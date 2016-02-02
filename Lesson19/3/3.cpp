#include <iostream>
using namespace std;

/*
Напишите функцию, которая принимает два целых числа, и определяет большее из них

*/

int max(int a, int b);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	cout << max(2, 3);
	

	cout << endl;
	system("pause");
}

int max(int a, int b) {
	return (a > b ? a : b);
}