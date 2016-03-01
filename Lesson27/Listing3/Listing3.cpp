#include <stdio.h>
#include <windows.h>

char* Rus(const char* text);
int rus(unsigned char);

unsigned char word[20];

void main(void)
{
	unsigned char ch;
	int i = 0;
	while ((ch = getchar()) != (unsigned char)EOF)
	{
		if (ch == '\n' || ch == '\t' || ch == ' ')
			continue;
		else
		{
			if (rus(ch))
				word[i++] = ch;
			else
				printf(Rus("\n Не русская буква %d \n"), ch);
		}
	}

	printf("%s \n %d \n", word, i);

	system("pause");
}

int rus(unsigned char ch)
{
	if ((ch >= 128) && (ch <= 175) || (ch >= 224) && (ch <= 241))
		return 1;
	else
		return 0;
}

char bufRus[256];
char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}
