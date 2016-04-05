#include<stdio.h>
#include <windows.h>

char* Rus(const char* text);
double sum(struct funds*);

struct funds
{
	static size_t count;
	char *bank;
	double bankfund;
	char *save;
	double savefund;
}
stan[2] = {
	{
		"Банк синьора Помидора",
		1023.43,
	"Сбережения и займы Снупи",
	4239.87
	},
	{
		"Банк Честного Джека",
		976.57,
	"Накопления по предварительному плану",
	1760.13
	}
};

void main(void)
{
	printf(Rus("В банке всего %.2f долларов.\n"), sum(stan));
}

double sum(struct funds *money)
{
	double total;
	int i;
	for (i = 0, total = 0; i<2; i++, money++)
		total += money->bankfund + money->savefund;
	return(total);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
