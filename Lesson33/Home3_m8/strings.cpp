#include <string.h>
#include <math.h>
#include "utils.h"
#include <malloc.h>

char* str_pos_del(char* str, size_t pos)
{
	size_t i, n = strlen(str);
	for (i = pos; i <= n; ++i)
	{
		*(str + i) = *(str + i + 1);
	}
	return str;
}


char* str_pos_add(char* str, size_t pos, const char ch)
{
	size_t i, n = strlen(str);
	for (i = n + 1; i > pos; --i)
	{
		*(str + i) = *(str + i - 1);
	}
	*(str + i) = ch;
	return str;
}


char* str_chr_del(char* str, const char ch)
{
	size_t i = 0;
	while (*(str + i))
	{
		if (*(str + i) == ch)
		{
			str_pos_del(str, i);
		}
		else
		{
			++i;
		}
	}
	return str;
}


char* str_chr_replace(char* str, const char find, const char replace)
{
	size_t i = 0;
	while (*(str + i))
	{
		if (*(str + i) == find)
		{
			*(str + i) = replace;
		}
		++i;
	}
	return str;
}


size_t str_chrs_count(const char* str, const char* find)
{
	size_t count = 0;
	while (*str)
	{
		if (strchr(find, *str))
			++count;
		++str;
	}
	return count;
}


size_t str_chr_count(const char* str, char find)
{
	size_t count = 0;
	while (*str)
	{
		if (*str == find)
			++count;
		++str;
	}
	return count;
}


__int8 str_cmp(const char * str1, const char * str2)
{
	while (*str1 && *str2)
	{
		if (*str1 > *str2)
			return 1;
		if (*str1 < *str2)
			return -1;
		++str1;
		++str2;
	}
	if (*str1) return 1;
	if (*str2) return -1;
	return 0;
}


__int64 str_to_int(const char* str)
{
	size_t i, j = 0;
	__int64 tmp = 0;
	__int8 sign = 1;

	if (*str == '-')
	{
		sign = -1;
		++str;
	}

	for (i = strlen(str); i --> 0;)
	{
		tmp += (*(str + i) - '0') * (__int64)pow(10, j++);
	}
	return tmp * sign;
}


char* int_to_str(__int64 num)
{
	size_t length = num_char_count(num) - 1;
	char* str = (char*)calloc(length + 2, sizeof(char));
	if (num < 0)
		*str = '-';
	if (!num)
		*str = '0';

	num = abs(num);
	while(num)
	{
		*(str + length--) = '0' + num % 10;
		num /= 10;
	}
	return str;
}


char* str_to_upper(char* str)
{
	size_t i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
			*(str + i) = *(str + i) - 'a' + 'A';
		++i;
	}
	return str;
}


char* str_to_lower(char* str)
{
	size_t i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) = *(str + i) + 'a' - 'A';
		++i;
	}
	return str;
}


char* str_rev(const char* str)
{
	size_t i, length = strlen(str);
	char* new_str = (char*)calloc(length + 1, sizeof(char));

	for (i = 0; i < length; ++i)
	{
		*(new_str + i) = *(str + length - i - 1);
	}
	return new_str;
}


char* str_str_replace(const char* str, const char* find, const char* replace)
{
	size_t str_len = strlen(str);
	size_t find_len = strlen(find);
	size_t replace_len = strlen(replace);
	size_t new_str_len = 0;
	size_t alloc = str_len + 1;

	char* new_str = (char*)calloc(alloc, sizeof(char));

	size_t i, j, k, start = 0;
	__int8 flag;

	for (i = 0; i <= str_len - find_len; ++i)
	{
		flag = 1;
		for (j = 0; j < find_len; ++j)
		{
			if (*(str + i + j) != *(find + j))
			{
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			if (i - start + new_str_len + replace_len > alloc)
				new_str = (char*)realloc(new_str, sizeof(char) * (alloc += 16));
			for (k = 0; k < i - start; ++k)
			{
				*(new_str + new_str_len++) = *(str + start + k);
			}
			for (k = 0; k < replace_len; ++k)
			{
				*(new_str + new_str_len++) = *(replace + k);
			}
			start = i + find_len;
			i += find_len - 1;
		}
	}
	if (start != str_len)
	{
		if (i - start + new_str_len + replace_len > alloc)
			new_str = (char*)realloc(new_str, sizeof(char) * (alloc += 16));
		for (k = start; k < str_len; ++k)
		{
			*(new_str + new_str_len++) = *(str + k);
		}
	}
	*(new_str + new_str_len++) = '\0';
	return (char*)realloc(new_str, sizeof(char) * new_str_len + 1);
}