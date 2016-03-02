#include <stdio.h>
#include <windows.h>
char* Rus(const char* text);

void main(void)
{
	int dates[4], *pti, index;
	float bills[4], *ptf;
	pti = dates; /*  присвоить адрес массива указателю */
	ptf = bills;
	for (index = 0; index<4; index++)
		printf(Rus("Указатели  +%d : %10u  %10u \n"), index, pti + index, ptf + index);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
