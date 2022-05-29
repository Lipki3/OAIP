#include "Header.h"


void del(struct tree** root) {
	if (!*root) {
		puts("Tree is empty\n");
		return;
	}
	struct tree* temp1, * temp2, * temp3;
	char str[20];   // ������ ��� ������� ����������
	int k;          // ��������� ��������� ���� �����
	int flag;
	rewind(stdin);
	puts("Enter word you want delete: ");
	fgets(str, 20, stdin);        // ������ ��� ������ ���� � ������
	rewind(stdin);
	str[strlen(str) - 1] = '\0';
	temp2 = temp1 = *root;     // temp1 � temp2 ��������������� �� ������ ������
	flag = 0;                  // 1 - ������� ������ �� ����� ������
	do {                       // ���� ������ ���������� �� ������ ���� dr1
		if (!(k = strcmp(str, temp1->eng)))
			flag = 1;          // ��������� ���� �� ������� st ������
		if (k < 0) {           // ����. ������  <  ������ � ������������� ����
			if (temp1->L) {    // �������� ������ �� ���� temp1 ����������
				temp2 = temp1; // ���������� ������� ����
				temp1 = temp1->L;  // ��������� ����� ����� ���� ������
			}
			else flag = 1;     // ����� �� ����� do ... while ��� ������������ ���������� � ������
		}
		if (k > 0) {           // ����. ������  >  ������ � ������������� ����
			if (temp1->R) {    // �������� ������� �� ���� temp1 ����������
				temp2 = temp1;      // ���������� ������� ����
				temp1 = temp1->R;   // ��������� ����� ������ ���� ������
			}
			else flag = 1;     // ����� �� ����� do ... while ��� ������������ ���������� � ������
		}
	} while (!flag);
	if (k) {
		puts("No matches found.\n");
		return;
	}
	else {
		k = strcmp(temp1->eng, temp2->eng);
		temp3 = temp1;          // ���������� ��������� ������� ������
		if (k < 0) {            // ��������� ������� < ����������
			if (temp1->R) {     // � ������� temp1 ���� ����� ������
				temp3 = temp1->R;   // ������� �� ������� ������ �� ��������� � �����
				while (temp3->L)
					temp3 = temp3->L;  // ����� ������� � null �����
				temp2->L = temp1->R;   // ����� ��������� ������� temp1
				temp3->L = temp1->L;
			}
			else 
				temp2->L = temp1->L;  // ������ �������� ������� temp1, �� ������� ������ �����
		}
		else {    // ��������� ������� > ����������
			if (temp1->L) {       // � ������� temp1 ���� ����� ������
				temp3 = temp1->L; // ������� �� ������� ����� �� ��������� � �����
				while (temp3->R)
					temp3 = temp3->R; // ����� ������� � null ������
				temp2->R = temp1->L; // ����� ��������� ������� temp1
				temp3->R = temp1->R;
			}
			else 
				temp2->R = temp1->R; // ������ �������� ������� temp1, �� ������� ����� �����
		}
		free(temp1);
	}
}

void clean(struct tree** root) {
	if (*root) {
		if ((*root)->L) 
			clean(&(*root)->L);
		if ((*root)->R) 
			clean(&(*root)->R);
		free(*root);
	}
}