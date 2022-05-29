#include "Header.h"


void add(struct tree** root) {
	struct tree* temp1 = (struct tree*)malloc(sizeof(struct tree));  // создание нового элемента(узла) добавляемого в дерево
	printf("Enter word: ");
	rewind(stdin);
	fgets(temp1->eng, 20, stdin); // ввод информации в этот новый элемент
	temp1->eng[strlen(temp1->eng) - 1] = '\0';
	printf("Enter translation: ");
	rewind(stdin);
	fgets(temp1->rus, 20, stdin); // ввод информации в этот новый элемент
	temp1->rus[strlen(temp1->rus) - 1] = '\0';
	rewind(stdin);
	temp1->L = temp1->R = NULL;
	if (!*root)  // если дерево пустое 
		*root = temp1;
	else {       // иначе поиск места в дереве куда добавляется новый элемент
		struct tree* temp2 = *root;
		while (temp2) {          // dr2-указатель "пробегает" по дереву до искомого узла или до конца ветви
			if (strcmp(temp1->eng, temp2->eng) == 0) {  // в дереве найдена искомая информация                                     
				free(temp1->eng);
				free(temp1);
				break;
			}
			else              // в узле dr2 дерева информация не совпадает с искомой
				if (strcmp(temp1->eng, temp2->eng) < 0)  // temp1->eng меньше temp2->eng 
					if (temp2->L == NULL) {              // из вершины temp2 нет движения влево 
						temp2->L = temp1;                // вставка узла temp1 в дерево
						temp2 = NULL;                    // для выхода из цикла while
					}
					else temp2 = temp2->L;               // переход к следующей вершине дерева слева от temp2
				else                                     // иначе: temp1->eng больше temp2->eng 
					if (temp2->R == NULL) {              // из вершины temp2 нет движения вправо 
						temp2->R = temp1;                // вставка узла temp1 в дерево
						temp2 = NULL;                    // для выхода из цикла while
					}
					else temp2 = temp2->R;
		}
		system("CLS");
	}
}