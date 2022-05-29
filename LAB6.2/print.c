#include "Header.h"

void print(struct tree* root) {
	struct stack {          // стек узлов дерева через которые осуществляется движение по ветви 
		struct Tree* tree;  // узел дерева  
		struct stack* stack;
	} *st, * st1 = NULL;
	if (!root) {
		puts("Tree is empty\n");
		return;
	}
	printf("1 - Non-Recursive\n2 - Recursive\n3 - Exit\n");
	int choice;
	int pr = 1;          // 1 - признак движения влево по ветви дерева
	while (!scanf("%d", &choice) || choice > 3 || choice < 1) {
		rewind(stdin);
		printf("Error!\n");
	}
	switch (choice) {
	case 1:
		st = (struct stack*)calloc(1, sizeof(struct stack));

		                 //  в стек заносится элемент содержащий
		st->tree = root; //  указатель на корень дерева для прохода по левому и правому поддеревьям

		st->stack = st1; // указатель на предыдущий эл-т стека 
		printf("|        Word        |     Translation    |\n");
		printf("|%-20s|%-20s|\n", root->eng, root->rus);
		while (st || root->R) {          // пока стек не пустой и есть движение вправо по дереву
			do { 
				if (pr && root->L)
					root = root->L;      // переход на узел слева
				else {
					if (root->R)
						root = root->R;  // переход на узел справа
				}
				pr = 1;  // сброс принудительного движения вправо

				if (root->L && root->R) {   // узел с 2 связями (вниз по дереву)
					st1 = st;         // запоминаем вершину стека
					st = (struct stack*)calloc(1, sizeof(struct stack));  // новый эл-т стека
					st->tree = root;  // указатель на найденый узел дерева
					st->stack = st1;  // указатель из вершины стека на предыдущий 
				}
				printf("|%-20s|%-20s|\n", root->eng, root->rus);
			} while (root->L || root->R);
			if (st) {
				                    // с вершины стека считываем узел(ветвления) дерева 
				root = st->tree;    // для возврата на этот узел ветвления в дереве
				st1 = st->stack;    // указатель вниз на следующий элемент стека
				free(st);           // удаление из стека указателя на выбранный узел
			}  
			st = st1;               // запоминаем новую вершину стека

									// это узел ветвления, устанавливаем признак принудительного 
			if (root->L && root->R) // перехода на узел расположенный справа от root, т.к.
				pr = 0;             // root->eng уже выведен при проходе слева
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