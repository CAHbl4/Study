#include <stdio.h>
#include <windows.h>

#define TWO 2
#define MSG "Серый кот поет веселую песню."
#define FOUR TWO*TWO
#define PX printf(Rus("Х равен %d.\n"),x)
#define FMT "Х равен %d.\n"

char* Rus(const char* text);

void main(void)
{
	int x = TWO;
	PX;
	x = FOUR;
	printf(Rus(FMT), x);
	printf("%s \n", Rus(MSG));
	printf("TWO : MSG \n");
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
