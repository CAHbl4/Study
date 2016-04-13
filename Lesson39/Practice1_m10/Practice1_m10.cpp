#include <stdio.h>
#include <windows.h>

/*
*
* amatu, 4/13/2016 9:18:20 AM
*/

char* Rus(const char* text);

typedef struct config {
	int pc_case : 1;
	int pc_mem : 1;
	int pc_video : 1;
} config_t;

void main() {

	//Code goes here

	system("pause");
}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}