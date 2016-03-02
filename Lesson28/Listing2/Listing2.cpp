#include <stdio.h>
#include <windows.h>

void main(void);
void change(int *, int *);
char* Rus(const char* text);

void main(void)
{
	int x = 5, y = 10;
	printf(Rus("Сейчас х=%d и y=%d. \n"), x, y);
	change(&x, &y);                        /* передача адресов функции */
	printf(Rus("Теперь х=%d и y=%d. \n"), x, y);
}

void change(int *u, int *v)
{
	int temp;
	temp = *u;
	*u = *v;
	*v = temp;
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
