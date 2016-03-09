#include<iostream>
using namespace std;

int Summa(int a, int b) {
	return a + b;
}

int Mult(int a, int b) {
	return a * b;
}


int main() {
	int(*ptr)(int, int) = Summa;

	cout << sizeof(ptr);
	cout << sizeof(Summa);
	return 0;
}