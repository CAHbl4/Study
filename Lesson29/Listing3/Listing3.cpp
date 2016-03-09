#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 09.03.2016 9:56:34
*/

char* Rus(const char* text);
int mean(int*, int);

void main(void)
{
	static int mas[3][4] = {
		{2,4,6,8},
		{100,200,300,400},
		{10,40,60,90}
	};
	printf(Rus("Среднее массива полностью равно %d\n"), mean(mas[0], 12));
}

int mean(int* ptmas, int n)
{
	int index;
	long sum;
	if (n > 0)
	{
		for (index = 0, sum = 0; index < n; index++)
			sum += *(ptmas + index);
		return ((int)(sum / n));
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

