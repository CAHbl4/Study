#include <iostream>
#include <iomanip>

using namespace std;

const int HOUR_S = 3600;			//������ � ����
const int MIN_S = 60;				//������ � ������
const int DAY_S = 86400;			//24 ����
const int ALARM_S = 25200;			//7 ����
const int REST_S = 72000;			//8 ������
const int TIME_TO_REST_S = 2700;	//����� ���� �� ��������� 45 ���

int HOUR(int s);
int MIN(int s);
int SEC(int s);

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*
	������������ ������ � ���������� ����� � ��������, ��������� � ������ ���.
	������� �� ����� ������� ����� � �����, ������� � ��������. ���������, ������� �����, ����� � ������ �������� �� ��������.
	*/

	//��� ���������

	int s;
	int cur_h, cur_m, cur_s;
	int tmp_h, tmp_m;
	int remain_h, remain_m, remain_s;

	cout << "������� ����� � �������� � ������ ���: ";
	cin >> s;

	if (s > DAY_S) cout << "������ �� �� ���������, ������ ��� ����� �����";
	else if (s < 1) cout << "������ ���� ��� �� �������";
	else {
		cur_h = HOUR(s);
		cur_m = MIN(s);
		cur_s = SEC(s);

		remain_h = HOUR(DAY_S - s);
		remain_m = MIN(DAY_S - s);
		remain_s = SEC(DAY_S - s);

		cout << setw(2) << setfill('0');
		if (cur_h < 7) {
			cout << "������ ����, ����� �� ����� " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			cout << "��������� ��������� ����� ";

			tmp_h = HOUR(ALARM_S - s);
			tmp_m = MIN(ALARM_S - s);

			if (tmp_h) cout << tmp_h << " �. ";
			if (tmp_m) cout << tmp_m << " �. ";

			cout << endl;
			cout << "�� ����� ��� �������� " << remain_h << " �., " << remain_m << " �., " << remain_s << " �.";
		}

		else if (cur_h < 12) {
			cout << "������ ����, ����� �� ����� " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			cout << "� ������ 22 �������, ������ ����������. ������ ����� �� ����� �� �����, ������� ��� �������� �������." << endl;
			cout << "�� ����� ��� �������� " << remain_h << " �., " << remain_m << " �., " << remain_s << " �.";
		}

		else if (cur_h < 17) {
			cout << "������ ����, ����� �� ����� " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;

			tmp_h = HOUR(REST_S);
			tmp_m = MIN(REST_S);

			cout << "����� ����� �������� ��������� �����. �� ";
		
			cout << tmp_h << " �. ";
			if (tmp_m) cout << tmp_m << " �. ";

			cout << "�����a � ��� ������� ������ � ���������, ����� �������� � ";

			tmp_h = HOUR(REST_S - TIME_TO_REST_S);
			tmp_m = MIN(REST_S - TIME_TO_REST_S);

			cout << tmp_h << " �. ";
			if (tmp_m) cout << tmp_m << " �. ";

			cout << endl;
			cout << "�� ����� ��� �������� " << remain_h << " �., " << remain_m << " �., " << remain_s << " �.";
		}

		else {
			cout << "������ �����, ����� �� ����� " << cur_h << ":" << setw(2) << setfill('0') << cur_m << ":" << setw(2) << setfill('0') << cur_s << "." << endl;
			if (s < REST_S) {

				cout << "� ��� ������� ������ � ��������� \"Maude\" �� 8 �����. ";

				if (s < REST_S - TIME_TO_REST_S) {

					tmp_h = HOUR(REST_S - TIME_TO_REST_S - s);
					tmp_m = MIN(REST_S - TIME_TO_REST_S - s);

					cout << "����� �������� ����� ";

					if (tmp_h) cout << tmp_h << " �. ";
					if (tmp_m) cout << tmp_m << " �. ";

					cout << endl;
				}
				else cout << "�� ����� �� �� ������� �������" << endl;
			}
			else {
				cout << "������� �������� ������ ��� �������� �� ����������. ��������� ������." << endl;
			}
			cout << "�� ����� ��� �������� " << remain_h << " �., " << remain_m << " �., " << remain_s << " �.";
		}
	}

	cout << endl;
	system("pause");
}

int HOUR(int s) {
	return s / HOUR_S;
}

int MIN(int s) {
	return s / MIN_S - HOUR(s) * MIN_S;
}

int SEC(int s) {
	return s % MIN_S;
}
