#include <stdio.h>
#include <string.h>
#include <windows.h>

char* Rus(const char* text);

#define WORDS "Проверьте, пожалуйста, Вашу последнюю запись."

void main(void)
{
	static char *orig = Rus(WORDS);
	static char copy[60];
	puts(orig);
	puts(copy);
	strcpy(copy, orig);
	puts(orig);
	puts(copy);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
