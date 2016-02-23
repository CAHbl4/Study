#include <iostream>
using namespace std;

/*
Создать массив из N целых чисел, N  вводит пользователь. Заполнить массив случайным образом в диапазоне от 1 до 12. 
Каждое число это оценка по 12 бальной системе. Пользуясь указателем на массив целых чисел, посчитать процент двоек,
троек, четверок и пятерок. Двойка от 1 до 3 включительно, тройка от 4 до 6, четверка от 7 до 9, пятерка от 10 до 12.

*/
enum grade{TWO, THREE, FOUR, FIVE};

void fill_rand(int *arr, int length, int left, int right);
double grade_percent(int *arr, int length, grade grade);

void main() {
	setlocale(LC_CTYPE, "Rus");

	//Код программы

	int size;
	cin >> size;
	int *arr = new int[size];
	fill_rand(arr, size, 1, 12);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	
	cout << "Процент двоек: " << grade_percent(arr, size, TWO) << endl;
	cout << "Процент троек: " << grade_percent(arr, size, THREE) << endl;
	cout << "Процент четверок: " << grade_percent(arr, size, FOUR) << endl;
	cout << "Процент пятерок: " << grade_percent(arr, size, FIVE) << endl;
	
	delete[] arr;
	cout << endl;
	system("pause");
}

void fill_rand(int * arr, int length, int left, int right)
{
	for (int i = 0; i < length; i++)
	{
		*(arr + i) = rand() % (right - left + 1) + left;
	}
}

double grade_percent(int * arr, int length, grade grade)
{
	double result = .0;
	for (int i = 0; i < length; i++)
	{
		switch (grade)
		{
		case TWO:
			if (arr[i] >= 1 && arr[i] <= 3) result++;
			break;
		case THREE:
			if (arr[i] >= 4 && arr[i] <= 6) result++;
			break;
		case FOUR:
			if (arr[i] >= 7 && arr[i] <= 9) result++;
			break;
		case FIVE:
			if (arr[i] >= 10 && arr[i] <= 12) result++;
			break;
		}
	}
	return result / length * 100;
}
