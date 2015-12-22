#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	¬ычислить пройденное рассто€ние при пр€молинейном равноускоренном движении по формуле S = v*t + (a*t2) / 2, где v Ц скорость, t Ц врем€, а Ц ускорение.
	*/

	// од программы
	
	double S, v, t, a;

	cout << "¬ведите скорость (м/с): ";
	cin >> v;
	cout << "¬ведите ускорение (м/с^2): ";
	cin >> a;
	cout << "¬ведите врем€ (c): ";
	cin >> t;

	S = v * t + (a*t*t) / 2;

	cout << "¬ы проехали " << S << "м.";

	cout << endl;
	system("pause");
}