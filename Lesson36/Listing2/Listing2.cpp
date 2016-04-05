#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAXTIT 50
#define MAXAUT 30
#define MAXBKS 100
#define STOP ""
struct book
{
	char title[MAXTIT];
	char author[MAXAUT];
	float value;
};
char* Rus(const char* text);

void main(void)
{
	struct book libry[MAXBKS];
	int count = 0;
	int index;
	printf(Rus("Введите название книги:\n"));
	printf(Rus("Нажмите <Enter> в начале строки для останова.\n"));
	while (strcmp(gets_s(libry[count].title), STOP) != 0 && count<MAXBKS)
	{
		printf(Rus("Введите фамилию автора:\n"));
		gets_s(libry[count].author);
		printf(Rus("Введите цену:\n"));
		scanf("%f", &libry[count++].value);
		while (getchar() != '\n'); /* очистка строки ввода */
		if (count<MAXBKS)
			printf(Rus("Название следующей книги:\n"));
	}
	printf(Rus("Список введенных книг:\n"));
	for (index = 0; index<count; index++)
		printf("%s, %s, %f \n", libry[index].author, libry[index].title,
			libry[index].value);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
