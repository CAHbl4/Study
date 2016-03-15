#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

#define SIZE 80

void main(void)
{
	static char flower[SIZE];
	static char addou[] = "ы пахнут старыми ботинками.";
	puts(Rus("Назовите Ваш любимый цветок."));
	gets_s(flower);
	if ((strlen(addou) + strlen(flower) + 1) < SIZE)
		strcat(flower, Rus(addou));
	puts(flower);
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

