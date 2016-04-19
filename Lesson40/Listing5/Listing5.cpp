#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAB_SIZE 20
#define IN_1 0
#define OUT_1 1
char* Rus(const char* text);
void err(int e);

int main(int argc, char *argv[])
{
	FILE *in, *out;
	int  i;
	char ch;

	if (argc != 3)
	{
		printf(Rus("Синтаксис: <имя .exe файла> <входной_файл> <выходной файл>\n"));
		exit(1);
	}
	if ((in = fopen(argv[1], "rb")) == NULL)
	{
		printf(Rus("Нельзя открыть %s.\n"), argv[1]);
		exit(1);
	}
	if ((out = fopen(argv[2], "wb")) == NULL)
	{
		printf(Rus("Нельзя открыть %s.\n"), argv[2]);
		exit(1);
	}

	do
	{
		ch = getc(in);
		if (ferror(in))
			err(IN_1);
		/* если найдена табуляция, выводится
		соответствующее число пробелов */
		if (ch == '\t')
		{
			for (i = 0; i < TAB_SIZE; i++)
			{
				putc(' ', out);
				if (ferror(out))
					err(OUT_1);
			}
		}
		else
		{
			putc(ch, out);
			if (ferror(out))
				err(OUT_1);
		}
	} while (!feof(in));
	fclose(in);
	fclose(out);
	return 0;
}

void err(int e)
{
	if (e == IN_1)
		printf(Rus("Ошибка при вводе.\n"));
	else
		printf(Rus("Ошибка при выводе.\n"));
	exit(1);
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}