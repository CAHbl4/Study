#include <iostream>

using namespace std;

int x = 20;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//��� ���������

	int x = 10;
	{int x = 3;
	cout << x << endl;
	cout << ::x << endl;
	}
	cout << x << endl;

	cout << endl;
	system("pause");
}