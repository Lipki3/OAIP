#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	int* a;  // указатель на массив
	int i, j, n, m;
	setlocale(LC_ALL, "Rus");
	system("cls");
	printf("Введите количество строк: ");
	scanf_s("%d", &n);
	printf("Введите количество столбцов: ");
	scanf_s("%d", &m);
	// Выделение памяти
	a = (int*)malloc(n * m * sizeof(int));
	// Ввод элементов массива
	for (i = 0; i < n; i++)  // цикл по строкам
	{
		for (j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", (a + i * m + j));
		}
	}
	// Вывод элементов массива
	for (i = 0; i < n; i++)  // цикл по строкам
	{
		for (j = 0; j < m; j++)  // цикл по столбцам
		{
			printf("%5d ", *(a + i * m + j)); // 5 знакомест под элемент массива
		}
		printf("\n");
	}
	free(a);
	return 0;
}
