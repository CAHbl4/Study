#include <iostream>
using namespace std;

/*

*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы


	const int SZ = 5;
	int **arr = new int*[SZ];
	for (size_t i = 0; i < SZ; i++)
	{
		arr[i] = new int[i + 1];
		for (size_t j = 0; j < i + 1; j++)
		{
			arr[i][j] = j + 1;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	for (size_t i = 0; i < SZ; i++)
	{
		delete[] arr[i];
	}

	delete[] arr;


	cout << endl;
	system("pause");
}