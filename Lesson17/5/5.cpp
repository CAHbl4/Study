#include <iostream>
using namespace std;

/*
Дано число n и квадратный массив int A[n][n]. 
Проверьте, является ли массив симметричным относительно главной диагонали. 
Программа должна выводить слово yes для симметричного массива и слово no для несимметричного.
	
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int const N = 3;
	int arr[N][N];

	arr[0][0] = 0; arr[0][1] = 1; arr[0][2] = 2;
	arr[1][0] = 1; arr[1][1] = 2; arr[1][2] = 3;
	arr[2][0] = 2; arr[2][1] = 3; arr[2][2] = 4;

	bool flag = true;

	for (int i = 0; i < N - 1; i++)
	{
		for (int j = i; j < N - 1; j++)
		{
			if (arr[i + j][i] != arr[i][i + j]) { flag = false; break; }
		}
		if (!flag) break;
	}
	
	cout << (flag ? "yes" : "no");


	cout << endl;
	system("pause");
}