#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

void main(void);
int mean(int *, int);

void main(void)
{
	static int mas[4] = { 100,200,300,400 };
	printf(Rus("Среднее массива равно %d \n"), mean(mas, 4));
}

int mean(int *ptmas, int n)
{
	int index;
	long sum;
	if (n>0)
	{
		for (index = 0, sum = 0; index<n; index++)
			sum += *(ptmas + index);
		return (int)(sum / n);
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
