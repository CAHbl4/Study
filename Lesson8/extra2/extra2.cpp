#include <iostream>

using namespace std;

void main() {
	setlocale(LC_CTYPE, "Rus");

	/*

	*/

	//��� ���������

	char s[421] = "���������������������_����_���������_���������������������_�����_�������������_������������������������������_�����_���_�����������������_���������������__����������������������������_����������__���������_�������_����������������_���������������������������������������������������_�����������������������������������������������������������__��������������������������������_�_�����_����������������������������������";
	char a[34] = "��������������������������������_";
	char key[5] = "����";

	int n;

	for (int i = 0; i < 420; i++) {									//���� �� ������
		for (int k = 0; k < 4; k++) {								//��������� ������� ����� ��� �������� �������
			if (i % 4 == k) {										
				for (int j = 0; j < 33; j++) {						//���� �� ��������
					if (s[i] == a[j]) {								//���� ������ ������ ��������� � �������� ��������
						for (n = 0; n < 33; n++) {				
							if (key[k] == a[n]) break;				//��������� ���������� ����� ������� ����� � ��������
						}
						s[i] = (j - n < 0) ? a[j - n + 33] : a[j - n];		//�������� �� ���������� ����� ����� 
						break;
					}
				}
				break;
			}
		}
		cout << s[i];
	}

	cout << endl;
	system("pause");
}