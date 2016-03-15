#include <stdio.h>
#include <windows.h>
char* Rus(const char* text);

void main(void)

{
	static char name1[10], name2[11];
	int count;
	printf(Rus("Введите два имени\n"));
	count = scanf("%s %10s", name1, name2);
	printf(Rus("Считано %d имени %s и %s\n"), count, name1, name2);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}