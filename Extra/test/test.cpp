#include <iostream>
using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");
	int i, j;
	int **arr = (int**)malloc(sizeof(int*) * 3);

	printf("Исходный массив\n");
	for (i = 0; i < 3; ++i)
	{
		arr[i] = (int*)malloc(sizeof(int) * 3);
		for (j = 0; j < 3; ++j)
		{
			arr[i][j] = rand() % 10;
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}


	int max_i = 0, max_j = 0, max = arr[0][0];
	int *ptmp, tmp;

	for(i = 0; i <3; ++i)
	{
		for (j = 0; j< 3;++j)
		{
			if (arr[i][j] > max)
			{
				max = arr[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	ptmp = arr[0];
	arr[0] = arr[max_i];
	arr[max_i] = ptmp;

	printf("Поменяли строки\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

	for (i = 0; i < 3; ++i)
	{
		tmp = arr[i][0];
		arr[i][0] = arr[i][max_j];
		arr[i][max_j] = tmp;
	}

	printf("Поменяли столбцы\n");
	for (i = 0; i < 3; ++i)
	{
		for (j = 0; j < 3; ++j)
		{
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}

}