#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	��������� ������ �� 10 ��������� ���������� ������� � ��������� [0..100] � ������������� ��� �� ��������� �����.

	*/

	//��� ���������

	const int N = 10;
	int arr[N];
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 101;
	}
	
	bool sorted;
	int j = 0;
	do {
		sorted = true;
		for (int i = 0; i < N - 1 - j; i++)
		{
			if (arr[i] % 10 > arr[i + 1] % 10) {
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				sorted = false;
				for (int i = 0; i < N; cout << arr[i] << ' ', i++);
				cout << endl;
			}
		}
		j++;
	} while (!sorted);

	cout << endl;
	system("pause");
}