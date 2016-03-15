#include <stdio.h>
#include <string.h>
void main(void)
{
	printf("%d\n", strcmp("A", "A"));
	printf("%d\n", strcmp("A", "B"));
	printf("%d\n", strcmp("B", "A"));
	printf("%d\n", strcmp("C", "A"));
	printf("%d\n", strcmp("apples", "apple"));
	printf("%d\n", strcmp("apple", "apples"));
}
