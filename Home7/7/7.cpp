#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	Написать программу для вычисления значения логического выражения для заданных переменных a=false, b=true, c=false, d=true;
	а) a||b&&!a&&d
	б) a&&b||!c||d

	*/

	//Код программы

	bool a = false, b = true, c = false, d = true;

	cout << "Результат логического выражения a||b&&!a&&d для a=false, b=true, c=false, d=true будет: " << (a || b && !a && d ? "true" : "false"); //Не у верен что я понял задание правильно
	cout << endl;
	cout << "Результат логического выражения a&&b||!c||d для a=false, b=true, c=false, d=true будет: " << (a && b || !c || d ? "true" : "false");

	cout << endl;
	system("pause");
}