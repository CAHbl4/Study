#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������� �� ����� ������ ����������� �����������. ������ ������� �������� ������ � ����������.
	
	*/

	//��� ���������

	int a;
	cout << "������� �������: ";
	if (cin >> a) {
		//for (int i = 1; i <= a; i++) {
		//	for (int j = 1; j <= a; j++) {
		//		if (a - i < j) cout << "*"; else cout << " ";
		//	}
		//	cout << endl;
		//}
		//cout << endl;
		//for (int i = 1; i <= a; i++) {
		//	for (int j = 1; j <= a; j++) {
		//		if (a - i > j) cout << "*"; else cout << " ";
		//	}
		//	cout << endl;
		//}
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if ( a - i < j && a - j < i) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else cout << "������ �����!";


	cout << endl;
	system("pause");
}