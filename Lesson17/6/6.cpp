#include <iostream>
using namespace std;

/*
ִאםû קטסכא n ט m. ׁמחהאיעו לאססטג int A[n][m] ט חאןמכםטעו ודמ סכוהף‏שטל מבנאחמל
		0   1   3   6  10  14
		2   4   7  11  15  18
		5   8  12  16  19  21
		9  13  17  20  22  23
*/

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Êמה ןנמדנאללû

	int const N = 4, M = 6;
	int arr[N][M];
	int t = 0;

	for (int k = 0; k <= N + M - 2; k++)
	{
		for (int i = 0; i < N; i++)
		{
			int j = k - i;
			if (j >= 0 && j < M) {
				arr[i][j] = t++;
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout.width(2);
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}


	cout << endl;
	system("pause");
}