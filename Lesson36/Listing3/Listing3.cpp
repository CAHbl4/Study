#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);

#define LEN 20
struct names
{
	char first[LEN];
	char last[LEN];
};
struct guy
{
	struct names handle;
	char food[LEN];
	char job[LEN];
	float income;
};

void main(void)
{
	static struct guy fellow[2] =
	{
		{
			{
				"Франко",
				"Уотэл"
			},
		"Баклажан",
		"Вязальщик половиков",
		15000.00
		},
		{
			{
				"Родней",
				"Свибли"
			},
		"Лососевый мусс",
		"Декоратор интерьера",
		35000.00
		}
	};
	struct guy *him; /* указатель на структуру */
	printf("sizeof(him) = %d\n", sizeof(him));
	printf(Rus("Адрес №1: %u №2: %u \n"), &fellow[0], &fellow[1]);
	him = &fellow[0];  /* указатель ссылается на fellow[0]*/
	printf(Rus("Указатель №1:  %u  №2: %u \n"), him, him + 1);
	printf("him->food is %s\n", Rus(him->food));
	printf("him->handle.last is %s\n", Rus(him->handle.last));
	printf("him->income = %.2f (*him).income= %.2f\n", him->income, (*him).income);
	him++;           /* указывает на следующую структуру */
	printf("him->food is %c\n", him->food[0]);
	printf("him->handle.last is %s\n", Rus(him->handle.last));
	printf("him->income = %.2f (*him).income= %.2f\n", him->income, (*him).income);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
