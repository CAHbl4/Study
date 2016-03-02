#include <cstdlib>

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

bool is_simple(int a) {
	for (int i = 2; i < a / 2; i++)
	{
		if (!(a % i)) return false;
	}
	return true;
}