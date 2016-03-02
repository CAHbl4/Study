#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	int arr[10];
	int max1 = 0, max2 = 0;

	for (int i = 0; i < 10; i++)
	{
		arr[i] = rand();
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	for (int i = 1; i < 10; i++)
	{
		if (arr[i] >= arr[max2]) {
			max1 = max2;
			max2 = i;
		}

		if (arr[i] < arr[max2] && arr[i] > arr[max1]) {
			max1 = i;
		}
		
	}

	cout << endl;
	cout << "arr[" << max1 << "] = " << arr[max1] << endl;
	cout << "arr[" << max2 << "] = " << arr[max2] << endl;

	cout << endl;
	system("pause");
}