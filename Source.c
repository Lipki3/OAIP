#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <malloc.h>
int main() {
	setlocale(LC_ALL, "Rus");
	int n = 10;
	int* mas;
	mas = (int*)malloc(n * sizeof(int));
	int j;
	for (j = 0; j < n; j++)
	{
		printf("������� %d: ", j);
		while (!scanf_s("%d", mas[j]))
		{
			printf("������! �� ����� �� �����.\n");
			rewind(stdin);
			printf("������� a[%d]: ", j);
		}
	}
}
