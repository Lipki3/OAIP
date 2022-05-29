#include <stdio.h>
#include <locale.h>
#define N 10   

void func2(int mas[10]);
int main()
{
	setlocale(LC_ALL, "Rus");
	int mas[N];
	int i = 0;

	for (i = 0; i < N; i++)
		//func1();
	{
		char c;
		printf("\nВведите mas[%d] = ", i);
		while (!scanf_s("%d%c", &mas[i], &c) || c != '\n')
		{
			printf("ОШИБКА! Вы ввели не число!\n");
			rewind(stdin);
			printf("\nВведите mas[%d] = ", i);
		}
	}

	func2(mas);
}
void func2(int mas[10])
{
    int p = 0; int i; int max = 0;  int  ind, maxi;
	for (int i = 0; i < N - 1; i++)
	{
		p = mas[i + 1] * mas[i];
		if (p > max)
		{
			max = p;
			ind = mas[i + 1];
			maxi = i + 1;
		}
	}
	printf("\nПроизведение: %d \nЗначение:  %d \n-------> Номер: %d", max, ind, maxi);
}


