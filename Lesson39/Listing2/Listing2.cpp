#include <stdio.h>
#include <windows.h>

#define SQUARE(x) x*x
#define PR(x) printf(Rus("x равен %d. \n"), x)

char* Rus(const char* text);

void main(void)
{
	int x = 4;
	int z;
	z = SQUARE(x);
	PR(z);
	z = SQUARE(2);
	PR(z);
	PR(SQUARE(x));
	PR(SQUARE(x + 2));
	PR(100 / SQUARE(2));
	PR(SQUARE(x++));
	printf("x = %d\n", x);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
