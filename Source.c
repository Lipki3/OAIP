#include <stdio.h>
#include <locale.h>
#define N 10   
//void func1(void);
void func2(void);
int main()
{
	setlocale(LC_ALL, "Rus");
	int mas[N];
	int i = 0;

	for (i = 0; i < N; i++)
	//func1();
	{
		char c;
		printf("\n������� mas[%d] = ", i);
		while (scanf_s("%d%c", &mas[i], &c) != 2 || c != '\n')
		{
			printf("������! �� ����� �� �����!\n");
			rewind(stdin);
			printf("\n������� mas[%d] = ", i);
		}
	}

		func2();
	/*int p;
	int  ind, maxi;
	p = 0;
    int max = 0;
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
	printf("\n������������: %d \n��������:  %d \n-------> �����: %d", max, ind, maxi);*/
		return 0;
	
}
/*void func1(void)
{
	int mas[N];
	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("\n������� mas[%d] = ", i);
		while ((scanf_s("%d", &mas[i]) != 1))
		{
			printf("������! �� ����� �� �����!\n");
			fflush(stdin);
			printf("\n������� mas[%d] = ", i);
		}
	}
}*/
	

void func2(void)
{
    int p = 0; int i; int max = 0; int mas[N]; int  ind, maxi;
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
	printf("\n������������: %d \n��������:  %d \n-------> �����: %d", max, ind, maxi);
}

