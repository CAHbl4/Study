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
		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j <= 0) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j >= 0) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j <= 0 && i + j <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (i - j >= 0 && i + j >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if ((i - j <= 0 && i + j <= a + 1) || (i - j >= 0 && i + j >= a + 1)) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (!((i - j < 0 && i + j < a + 1) || (i - j > 0 && i + j > a + 1))) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j - i <= 0 && i + j <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j - i >= 0 && i + j >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j + i <= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;

		cout << "�: " << endl;
		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= a; j++) {
				if (j + i >= a + 1) cout << "*"; else cout << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	else cout << "������ �����!";


	cout << endl;
	system("pause");
}