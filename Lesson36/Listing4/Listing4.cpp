﻿#include<stdio.h>
#include <windows.h>

char* Rus(const char* text);
double sum(double, double);

struct funds
{
	char *bank;
	double bankfund;
	char *save;
	double savefund;
}stan = {
	"Банк синьора Помидора",
	1023.43,
	"Сбережения и займы Снупи",
	4239.87
};

void main(void)
{
	extern struct funds stan;
	printf(Rus("У Стэна всего %.2f долларов.\n"), sum(stan.bankfund, stan.savefund));
}

double sum(double x, double y)
{
	return (x + y);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
