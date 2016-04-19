#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
char* Rus(const char* text);

int main(void)
{
	char str[80];
	FILE *fp;
	if ((fp = fopen("test.txt", "w")) == NULL)
	{
		printf(Rus("Ошибка при открытии файла.\n"));
		exit(1);
	}
	do
	{
		printf(Rus("Введите строку (пустую - для выхода):\n"));
		gets_s(str);
		strcat(str, "\n");  /* добавление разделителя строк */
		OemToCharA(str, str);
		fputs(str, fp);
	} while (*str != '\n');
	fclose(fp);
	return 0;
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
