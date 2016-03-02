#include <iostream>
using namespace std;

int main() {

	int a = 767;
	unsigned char *ptr_c = (unsigned char *)&a;

	cout << "Mem addr: ";
	for (int i = sizeof(a) - 1; i >= 0; i--)
	{
		cout.width(9);
		cout << hex << (int)ptr_c + i;
	}
	cout << endl;

	cout << "Binary  : ";
	for (int i = sizeof(a) - 1; i >= 0; i--)
	{
		cout << " ";
		for (int j = 7; j >= 0; j--)
		{
			cout << (*(ptr_c + i) >> j & 1);
		}
	}
	cout << endl;

	cout << "Decimal : ";
	for (int i = sizeof(a) - 1; i >= 0; i--)
	{
		cout.width(9);
		cout << dec << (int)*(ptr_c + i);
	}

	cout << endl;
	system("pause");
	return 0;
}