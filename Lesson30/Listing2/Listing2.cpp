#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

void main(void)
{
	char name[81];
	printf(Rus("Привет!!! Как Вас зовут? \n"));
	gets_s(name);
	printf(Rus("Хорошее имя, %s .\n"), name);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}