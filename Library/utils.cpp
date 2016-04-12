#include <malloc.h>

size_t num_char_count(__int64 num)
{
	size_t count = 0;
	if (num < 0)
		++count;
	do {
		++count;
		num /= 10;
	} while (num);
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

__int64 pow(__int64 base, __int64 exp)
{
	if (!exp) {
		return 0;
	}

	__int64 result = 1;
	while (exp)
	{
		if (exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}

__int64 _llabs(__int64 x) {
	return x < 0 ? x * -1 : x;
}