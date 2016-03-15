#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

void main(int argc, char *argv[])
{
	int count;
	for (count = 0; count<argc; count++)
		printf(" %s", Rus(argv[count]));
	printf("\n");
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
