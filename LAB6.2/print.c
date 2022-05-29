#include "Header.h"

void print(struct tree* root) {
	struct stack {          // ���� ����� ������ ����� ������� �������������� �������� �� ����� 
		struct Tree* tree;  // ���� ������  
		struct stack* stack;
	} *st, * st1 = NULL;
	if (!root) {
		puts("Tree is empty\n");
		return;
	}
	printf("1 - Non-Recursive\n2 - Recursive\n3 - Exit\n");
	int choice;
	int pr = 1;          // 1 - ������� �������� ����� �� ����� ������
	while (!scanf("%d", &choice) || choice > 3 || choice < 1) {
		rewind(stdin);
		printf("Error!\n");
	}
	switch (choice) {
	case 1:
		st = (struct stack*)calloc(1, sizeof(struct stack));

		                 //  � ���� ��������� ������� ����������
		st->tree = root; //  ��������� �� ������ ������ ��� ������� �� ������ � ������� �����������

		st->stack = st1; // ��������� �� ���������� ��-� ����� 
		printf("|        Word        |     Translation    |\n");
		printf("|%-20s|%-20s|\n", root->eng, root->rus);
		while (st || root->R) {          // ���� ���� �� ������ � ���� �������� ������ �� ������
			do { 
				if (pr && root->L)
					root = root->L;      // ������� �� ���� �����
				else {
					if (root->R)
						root = root->R;  // ������� �� ���� ������
				}
				pr = 1;  // ����� ��������������� �������� ������

				if (root->L && root->R) {   // ���� � 2 ������� (���� �� ������)
					st1 = st;         // ���������� ������� �����
					st = (struct stack*)calloc(1, sizeof(struct stack));  // ����� ��-� �����
					st->tree = root;  // ��������� �� �������� ���� ������
					st->stack = st1;  // ��������� �� ������� ����� �� ���������� 
				}
				printf("|%-20s|%-20s|\n", root->eng, root->rus);
			} while (root->L || root->R);
			if (st) {
				                    // � ������� ����� ��������� ����(���������) ������ 
				root = st->tree;    // ��� �������� �� ���� ���� ��������� � ������
				st1 = st->stack;    // ��������� ���� �� ��������� ������� �����
				free(st);           // �������� �� ����� ��������� �� ��������� ����
			}  
			st = st1;               // ���������� ����� ������� �����

									// ��� ���� ���������, ������������� ������� ��������������� 
			if (root->L && root->R) // �������� �� ���� ������������� ������ �� root, �.�.
				pr = 0;             // root->eng ��� ������� ��� ������� �����
			else 
				break;
		}
		break;
	case 2:
		printf("|        Word        |     Translation    |\n");
		recursive(root);
		break;
	case 3:
		break;
	}
}

void recursive(struct tree* root) {
	if (root) {
		if (root->L)   
			recursive(root->L);  
		printf("|%-20s|%-20s|\n", root->eng, root->rus);
		if (root->R) 
			recursive(root->R); 
	}
}
void file(struct tree* root) {
	FILE* f = fopen("file.txt", "wb");
	if (root) {
		if (root->L)
			file(root->L);
		fwrite(root, sizeof(root), 1, f);
		if (root->R)
			file(root->R);
	}
}