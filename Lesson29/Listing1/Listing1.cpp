#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 09.03.2016 9:23:20
*/

char* Rus(const char* text);
int mean(int [], int);

void main(void)
{
	static int mas[3][4] = {
		{2,4,6,8},
		{100,200,300,400},
		{10,40,60,90}
	};
	int row;




	for (row = 0; row < 3; row++)
		printf(Rus("Среднее строки %d равно  %d \n"), row, mean(mas[row], 4));
}

int mean(int array[], int n)
{
	int index;
	long sum;
	if (n > 0)
	{
		for (index = 0 , sum = 0; index < n; index++)
			return sum / n;
	}
	else
	{
		printf(Rus("Нет массива.\n"));
		return 0;
	}
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

