#include <stdio.h>
#include <string.h> /*h-файл, где находится прототип функции*/
#include <windows.h>

char* Rus(const char* text);
void main(void);
void fit(char*, int);

void main(void)
{
	static char mesg[] = "Привет! Я Ваша тетя.";
	puts(Rus(mesg));
	fit(mesg, 10);
	puts(Rus(mesg));
}

void fit(char* string, int size)
{
	if (strlen(string) > size)
		*(string + size) = '\0';
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

