#include<stdio.h>
#include<windows.h>

#define MAXTIT 50
#define MAXAUT 30

char* Rus(const char* text);

struct book
{
	char title[MAXTIT];
	char author[MAXAUT];
	float value;
};

void main(void)
{
	struct book libry;
	printf(Rus("Введите название книги:\n"));
	gets_s(libry.title);
	printf(Rus("Введите фамилию автора:\n"));
	gets_s(libry.author);
	printf(Rus("Введите цену:\n"));
	scanf("%f", &libry.value);
	printf(Rus("Ваши введенные данные по книге:\n"));
	printf("%s,%s,%10.2f\n", libry.author, libry.title, libry.value);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
