#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int i = 0; int j = 0;
	int n; float m;

	printf("������� ���������� ����� (3 � ������): ");
	while (!scanf_s("%d", &n) || n < 3)
	{
		printf("������! �� ����� �� ����� ��� ����� ����� ������ 3\n");
		rewind(stdin);
		printf("������� ���������� �����: ");
	}
	float* sud;
	sud = (float*)malloc(n * sizeof(float));
	for (i = 0; i < n; i++)
	{
		printf("������ ����� �%d: ", i + 1);
		while (!scanf_s("%f", &sud[i]))
		{
			printf("������! �� ����� �� �����\n");
			rewind(stdin);
			printf("������ ����� �%f: ", i + 1);
		}
	}

	// ���������� ������� ��������
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			if (sud[j - 1] > sud[j])
			{
				m = sud[j - 1];
				sud[j - 1] = sud[j];
				sud[j] = m;
			}
		}

	}
	printf("\n������ ����� �� �����������:  ");
	for (i = 0; i < n; i++)
		printf("%4.1f ", sud[i]);

	// ������� ������� ������, ������� � �������� �������� (i=2). i1 ��������
	float sum = sud[1], sr; int d = 1;
	for (i = 2; i < n - 1; i++)
	{
		d++;
		sum = sum + sud[i];
	}
	sr = sum / d;
	printf(" ������� ������ ����� ��� ������ � ������: %4.2f ", sr);
	free(sud);
}