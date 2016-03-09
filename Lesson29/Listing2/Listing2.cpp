#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 09.03.2016 9:44:07
*/

char* Rus(const char* text);
int mean(int [][4], int, int);

void main(void)
{
	static int mas[3][4] = {
		{2,4,6,8},
		{100,200,300,400},
		{10,40,60,90}
	};
	printf(Rus("Среднее массива полностью равно  %d \n"), mean(mas, 3, 4));
}

int mean(int array[][4], int i, int j)
{
	long sum;
	if (i > 0 && j > 0)
	{
		for (i = 0 , sum = 0; i < 3; i++)
		{
			for (j = 0; j < 4; j++)
				sum += long(array[i][j]);
		}
		return ((int)(sum / (i * j)));
	}
	else
	{
		printf(Rus("Нет массива.\n"));
		return (0);
	}
}


char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

