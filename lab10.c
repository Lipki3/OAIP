#include <stdio.h>          
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
int mass(int** A, int** B, int n);
int func1(int n, int **B, int* max, int i, int j); 
int func2(int i, int n, int j, int **C, int **A, int* max);
int func3(int n, int**B, int*pr, int i, int j);
int func4(int i, int j, int n, int**D, int**C, int* pr);
int func5(int i, int n, int**A, int**B, int**C, int**D, int*max, int*pr);
int main()
{
	setlocale(LC_ALL, "Rus");
	int** A; int** B; int** C; int** D; int* max; int* pr; int n; int i = 0; int j = 0;
	//-----------------------------------------------
	//ВВОД РАЗМЕРНОСТИ МАССИВОВ 
	printf("Введите размерность массива: ");
	while (!scanf_s("%d", &n) || n < 1)
	{
		printf("Ошибка! Вы ввели не число или число меньше 1.\n");
		rewind(stdin);
		printf("Введите размерность массива: ");
	}
	//-----------------------------------------------
	// ВЫДЕЛЕНИЕ ПАМЯТИ ПОД МАССИВЫ
	A = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) 
		*(A + i) = (int*)malloc(sizeof(int) * n); 
	B = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) 
		*(B + i) = (int*)malloc(sizeof(int) * n);
	C = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++) 
		*(C + i) = (int*)malloc(sizeof(int) * n);
	D = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
		*(D + i) = (int*)malloc(sizeof(int) * n);
	max = (int*)malloc(n * sizeof(int));
	pr = (int*)malloc(n * sizeof(int));
	//-----------------------------------------------
	// ЗАПОЛНЕНИЕ И ВЫВОД НА ЭКРАН НАЧАЛЬНЫХ МАССИВОВ А, B
	mass(A, B, n);
	//-----------------------------------------------
	//ЗАПОЛНЕНИЕ МАССИВА max МАКСИМАЛЬНЫМИ ЭЛЕМЕНТАМИ СТРОК И ВЫВОД МАССИВА
	func1(n, B, max, i, j);
	//-----------------------------------------------
	// ЗАПОЛНЕНИЕ И ВЫВОД МАССИВА С
	func2(i, n, j, C, A, max);
	//-----------------------------------------------
	// ЗАПОЛНЕНИЕ МАССИВА pr ПРОИЗВЕДЕНИЕМ ЭЛЕМЕНТОВ СТРОК МАССИВА B И ВЫВОД
	func3(n, B, pr, i, j);
	//-----------------------------------------------
	// ЗАПОЛНЕНИЕ И ВЫВОД МАССИВА D
	func4(i, j, n, D, C, pr);
	//-----------------------------------------------
	// ОСВОБОЖДЕНИЕ ПАМЯТИ
	func5(i, n, A, B, C, D, max, pr);
	return 0;
}
int mass(int** A, int** B, int n)
{
	int rnd; int i = 0; int j = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			rnd = rand() % 10 + 1;
			A[i][j] = rnd;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			rnd = rand() % 10 + 1;
			B[i][j] = rnd;
		}
	}
	printf("\nИсходный массив A:");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%d ", A[i][j]);
		}
	}
	printf("\nИсходный массив B:");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
		{
			printf("%d ", B[i][j]);
		}
	}
	printf("\n ---- функция mass выполнена ----");
}
int func1(int n, int **B, int* max, int i, int j)
{
	int a = 0, num;
	for (int i = 0; i < n; i++)
	{
		num = B[i][0];
		for (int j = 1; j < n; j++)
		{
			if (num < B[i][j])
			{
				max[a] = B[i][j];
				num = B[i][j];
			}
			else
				max[a] = num;
		}
		a++;
	}
	printf("\nМаксимальные элементы строк массива В: \n");
	for (i = 0; i < n; i++)
		printf(" %d", max[i]);
	printf("\n ---- функция func1 выполнена ----");
}
int func2(int i, int n, int j, int **C, int **A, int* max)
{
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			C[i][j] = A[i][j] * max[i];
	}
	printf("\nМассив С (полученный путём умножения строк массива А на максимальный элемент соответствующей строки массива В): ");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf(" %d", C[i][j]);
	}
	printf("\n ----- функция func2 выполнена ----");
}
int func3(int n, int**B, int*pr, int i, int j)
{
	int k = 0, prz;
	for (int i = 0; i < n; i++)
	{
		prz = B[i][0];
		for (int j = 1; j < n; j++)
		{
			prz = prz * B[i][j];
			pr[k] = prz;
		}
		k++;
	}
	printf("\nПроизведения элементов строк массива В: \n");
	for (i = 0; i < n; i++)
		printf(" %d", pr[i]);
	printf("\n ---- функция func3 выполнена ----");
}
int func4(int i, int j, int n, int**D, int**C, int* pr)
{
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
			D[i][j] = C[j][i] + pr[i];
	}
	printf("\nМассив D (полученный путём прибавления к элементам каждого столбца массива С произведения элементов соответствующих строк массива В: ");
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf(" %d", D[j][i]);
	}
	printf("\n ---- функция func4 выполнена ----");
}
int func5(int i, int n, int**A, int**B, int**C, int**D, int*max, int*pr)
{
	for (i = 0; i < n - 1; i++)
		free(A[i]);
	free(A);
	for (i = 0; i < n - 1; i++)
		free(B[i]);
	free(B);
	for (i = 0; i < n - 1; i++)
		free(C[i]);
	free(C);
	for (i = 0; i < n - 1; i++)
		free(D[i]);
	free(D);
	free(max);
	free(pr);
	printf("\n ---- функция func5 выполнена ----");
}
