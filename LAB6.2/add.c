#include "Header.h"


void add(struct tree** root) {
	struct tree* temp1 = (struct tree*)malloc(sizeof(struct tree));  // �������� ������ ��������(����) ������������ � ������
	printf("Enter word: ");
	rewind(stdin);
	fgets(temp1->eng, 20, stdin); // ���� ���������� � ���� ����� �������
	temp1->eng[strlen(temp1->eng) - 1] = '\0';
	printf("Enter translation: ");
	rewind(stdin);
	fgets(temp1->rus, 20, stdin); // ���� ���������� � ���� ����� �������
	temp1->rus[strlen(temp1->rus) - 1] = '\0';
	rewind(stdin);
	temp1->L = temp1->R = NULL;
	if (!*root)  // ���� ������ ������ 
		*root = temp1;
	else {       // ����� ����� ����� � ������ ���� ����������� ����� �������
		struct tree* temp2 = *root;
		while (temp2) {          // dr2-��������� "���������" �� ������ �� �������� ���� ��� �� ����� �����
			if (strcmp(temp1->eng, temp2->eng) == 0) {  // � ������ ������� ������� ����������                                     
				free(temp1->eng);
				free(temp1);
				break;
			}
			else              // � ���� dr2 ������ ���������� �� ��������� � �������
				if (strcmp(temp1->eng, temp2->eng) < 0)  // temp1->eng ������ temp2->eng 
					if (temp2->L == NULL) {              // �� ������� temp2 ��� �������� ����� 
						temp2->L = temp1;                // ������� ���� temp1 � ������
						temp2 = NULL;                    // ��� ������ �� ����� while
					}
					else temp2 = temp2->L;               // ������� � ��������� ������� ������ ����� �� temp2
				else                                     // �����: temp1->eng ������ temp2->eng 
					if (temp2->R == NULL) {              // �� ������� temp2 ��� �������� ������ 
						temp2->R = temp1;                // ������� ���� temp1 � ������
						temp2 = NULL;                    // ��� ������ �� ����� while
					}
					else temp2 = temp2->R;
		}
		system("CLS");
	}
}