#include <stdio.h> 
#include<windows.h>
char* Rus(const char* text);

void main(int argc, char *argv[])
{
	FILE *in, *out;
	int ch;
	static char name[20];
	int count = 0;
	if (argc<2)
		printf(Rus("Извините! Не введено наименование входного файла. \n"));
	else
	{
		if ((in = fopen(argv[1], "r")) != NULL)
		{
			strcpy(name, argv[1]);
			strcat(name, ".red");
			out = fopen(name, "w");
			while ((ch = getc(in)) != EOF)
				if (count++ % 3 == 0)
					fputc(ch, out);
			fclose(in);
			fclose(out);
		}
		else
			printf(Rus("Нет возможности открыть файл \" %s \" .\n "), argv[1]);
	}
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}