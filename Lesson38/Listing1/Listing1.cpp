﻿#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

char *func()[3];

void main(void)
{
	int  *     oof[3]      [4];
	*oof[0][0] = 3;

	char *func()[3];
}
char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}