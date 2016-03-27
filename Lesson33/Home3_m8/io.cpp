#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "strings.h"
#include "io.h"


void flush_stream(FILE* fp)
{
	fseek(fp, 0, SEEK_END);
}


char* read_string(FILE* fp)
{
	char* str, ch;
	size_t len = 0, alloc = 16;

	str = (char*)calloc(alloc, sizeof(char));

	while (EOF != (ch = fgetc(fp)) && ch != '\n')
	{
		str[len++] = ch;
		if (len == alloc)
		{
			str = (char*)realloc(str, sizeof(char) * (alloc += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return (char*)realloc(str, sizeof(char) * len);
}


char** read_strings(FILE* fp, char** str, size_t* count)
{
	char* s;
	int alloc = *count + 10;
	str = (char**)realloc(str, sizeof(char*) * alloc);

	while (((s = read_string(fp))) && str_cmp(s, HALT))
	{
		if (*count == alloc)
			str = (char**)realloc(str, sizeof(char*) * (alloc += 10));
		*(str + *count) = s;
		++(*count);
	}
	return (char**)realloc(str, sizeof(char*) * *count);
}


__int64 read_int(FILE* fp)
{
	__int64 n = 0;
	__int8 result;
	char ch;
	do
	{
		result = fscanf(fp, "%lld", &n);
		if (result == EOF)
		{
			fprintf(stderr, "Unexpected EOF\n");
			exit(74);
		}
		if (result == 0)
		{
			do
			{
				ch = fgetc(fp);
			} while (ch <= '0' && ch >= '9');
			fprintf(stderr, "Incorrect symbol\n");
		}
	} while (!result);

	flush_stream(fp);

	return n;
}

char read_char(FILE* fp)
{
	char ch = fgetc(fp);

	flush_stream(fp);

	return ch;
}