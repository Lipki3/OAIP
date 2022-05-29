#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int i, dl = 0; int n = 100;
	char str[100];
	printf("\nВведите строкy: ");
	for (i = 0; i < 100; i++) str[i] = 32;
	gets(str);
	int len = strlen(str);

	printf("\nЗаписанная строка: ");
	for (i = 0; i < n; i++)
		printf("%c", str[i]);
	int min = 100;
	for (i = 0; i < len; i++) {
		dl = 0;
		do {
				dl++;
				i++;
		} while (str[i] != ' ');
		if (dl < min) {
			if (i == len+1) min = dl - 1;
			else min = dl;
		}
	}

	printf("\nДлина самого короткого слова = %d", min);

	return 0;
}
}
