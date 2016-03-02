#include <stdio.h>
#include <windows.h>
using namespace std;

/*
Определить, есть ли в массиве простые числа. Если да, то вывести их на экран.
*/

char* Rus(const char* text);

void put(int arr[], int zize);
int is_prime(int a);
void print_primes(int arr[], int size);

void main() {

	//Писать код тут


}

char bufRus[256];

char* Rus(const char* text)
{
	CharToOemA(text, bufRus);
	return bufRus;
}

void put(int arr[], int zize)
{

}

int is_prime(int a)
{
	if (a < 2) return 1;
	int i;
	for (i = 2; i < a / 2; i++)
	{
		if (!(a % i)) return 1;
	}
	return 0;
}

void print_primes(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		if (is_prime(arr[i])) printf("%d ", arr[i]);
	}
}
