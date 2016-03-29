#include <math.h>
#include <malloc.h>

size_t num_char_count(__int64 num)
{
	size_t count = 1;
	if (num)
	{
		count = (size_t)(floorl(log10((double)llabs(num))) + 1);
		if (num < 0)
			++count;
	}
	return count;
}


__int8 is_digit(char ch)
{
	return (ch >= '0' && ch <= '9');
}


__int8 is_letter(char ch)
{
	return ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'));
}


void* free_ptr_ptr(void **ptr, size_t count)
{
	size_t i;
	for (i = 0; i < count; ++i)
	{
		free(*(ptr + i));
	}
	free(ptr);
	return NULL;
}