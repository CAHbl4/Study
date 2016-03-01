#include <iostream>

using namespace std;

//Quick sort
void qsort(int* arr, int n);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//Код программы

	cout << endl;
	system("pause");
}

void qsort(int* arr, int n)
{
	int l = 0, r = n - 1;
	int m = *(arr + n / 2);
	int tmp;

	do
	{
		while (*(arr + l) < m) l++;
		while (*(arr + r) > m) r--;

		if (l <= r)
		{
			tmp = *(arr + l);
			*(arr + l) = *(arr + r);
			*(arr + r) = tmp;
			l++;
			r--;
		}
	} while (l <= r);


	if (r > 0) qsort(arr, r + 1);
	if (n > l) qsort(arr + l, n - l);
}