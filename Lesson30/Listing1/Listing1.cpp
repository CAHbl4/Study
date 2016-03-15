#include <stdio.h>
#include <windows.h>
char* Rus(const char* text);

void main(void)
{
	printf("%s, %u, %c \n", Rus("Мы"), Rus("Любовь"), *Rus("Яблоко"));
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}