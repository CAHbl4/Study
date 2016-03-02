#include <stdio.h>
#include <windows.h>
void trystat(void);
char* Rus(const char* text);

void main(void)
{
	int count;
	for (count = 1; count <= 3; count++)
	{
		printf(Rus("Итерация %d : \n"), count);
		trystat();
	}
}

void trystat(void)
{
	int fade = 1;
	static int stay = 1;
	printf("fade=%d,  stay=%d \n", fade++, stay++);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
