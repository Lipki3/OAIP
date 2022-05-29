#include "Header.h"


void del(struct tree** root) {
	if (!*root) {
		puts("Tree is empty\n");
		return;
	}
	struct tree* temp1, * temp2, * temp3;
	char str[20];   // строка для анализа информации
	int k;          // результат сравнения двух строк
	int flag;
	rewind(stdin);
	puts("Enter word you want delete: ");
	fgets(str, 20, stdin);        // строка для поиска узла в дереве
	rewind(stdin);
	str[strlen(str) - 1] = '\0';
	temp2 = temp1 = *root;     // temp1 и temp2 устанавливаются на корень дерева
	flag = 0;                  // 1 - признак выхода из цикла поиска
	do {                       // цикл поиска удаляемого из дерева узла dr1
		if (!(k = strcmp(str, temp1->eng)))
			flag = 1;          // удаляемый узел со строкой st найден
		if (k < 0) {           // введ. строка  <  строки в анализируемом узле
			if (temp1->L) {    // движение налево из узла temp1 существует
				temp2 = temp1; // запоминаем текущий узел
				temp1 = temp1->L;  // считываем новый левый узел дерева
			}
			else flag = 1;     // выход из цикла do ... while при ненахождении информации в дереве
		}
		if (k > 0) {           // введ. строка  >  строки в анализируемом узле
			if (temp1->R) {    // движение направо из узла temp1 существует
				temp2 = temp1;      // запоминаем текущий узел
				temp1 = temp1->R;   // считываем новый правый узел дерева
			}
			else flag = 1;     // выход из цикла do ... while при ненахождении информации в дереве
		}
	} while (!flag);
	if (k) {
		puts("No matches found.\n");
		return;
	}
	else {
		k = strcmp(temp1->eng, temp2->eng);
		temp3 = temp1;          // запоминаем удаляемую вершину дерева
		if (k < 0) {            // удаляемая вершина < предыдущей
			if (temp1->R) {     // у вершины temp1 есть ветвь вправо
				temp3 = temp1->R;   // переход на вершину вправо от удаляемой и далее
				while (temp3->L)
					temp3 = temp3->L;  // поиск вершины с null влево
				temp2->L = temp1->R;   // обход удаляемой вершины temp1
				temp3->L = temp1->L;
			}
			else 
				temp2->L = temp1->L;  // просто удаление вершины temp1, не имеющей правой связи
		}
		else {    // удаляемая вершина > предыдущей
			if (temp1->L) {       // у вершины temp1 есть ветвь вправо
				temp3 = temp1->L; // переход на вершину влево от удаляемой и далее
				while (temp3->R)
					temp3 = temp3->R; // поиск вершины с null вправо
				temp2->R = temp1->L; // обход удаляемой вершины temp1
				temp3->R = temp1->R;
			}
			else 
				temp2->R = temp1->R; // просто удаление вершины temp1, не имеющей левой связи
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