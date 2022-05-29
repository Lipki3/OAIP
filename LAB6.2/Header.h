#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu(struct tree** root);
void del(struct tree** root);
void clean(struct tree** root);
void recursive(struct tree* root);
void print(struct tree* root);
void add(struct tree** root);
void file(struct tree** root);


struct tree {
	char eng[15];
	char rus[15];
	struct tree* L;
	struct tree* R;
};

