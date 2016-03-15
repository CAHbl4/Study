#include <iostream>
using namespace std;

void main()
{
	char str[] = "Alphabet - a b c d e f";
	char* ptr = strchr(str, 'a');
	while (ptr)
	{
		cout << ptr - str << '\t';
	}
}