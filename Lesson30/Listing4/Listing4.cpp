#include <stdio.h>
#include <windows.h>
#define DEF "Я есть строка"
char* Rus(const char* text);

void main(void)
{
	static char str1[] = "Массив инициализирован.";
	static char *str2 = "Указатель инициализирован.";
	static char dount[] = { 'H','E','E' };
	puts(dount);
	puts(Rus("Аргумент функции puts()."));
	puts(Rus(DEF));
	puts(Rus(str1));
	puts(Rus(str2));
	puts(Rus(&str1[4]));
	puts(Rus(str2 + 4));



}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
