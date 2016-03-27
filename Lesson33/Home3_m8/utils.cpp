#include <math.h>

size_t num_char_count(__int64 num)
{
	size_t count = 1;
	if (num)
	{
		count = (size_t)(floor(log10(abs(num))) + 1);
		if (num < 0)
			++count;
	}
	return count;
}

__int8 is_digit(char ch)
{
	return (ch >= '0' && ch <= '9');
}