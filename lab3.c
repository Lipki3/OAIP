#include <stdio.h>
#include <locale.h>
#include <math.h>
void func1(void);
int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Неравенство:7n^3 + 81n^2 - 10^6 < 0\n");
	func1();
		return 0;
}
void func1(void)
{
	int n, max = 0;
	float res = 0;
	n = 0;
	do	 
	{
		n++;
		res = 7 * pow(n, 3) + 81 * pow(n, 2) - pow(10, 6);
		if (res < 0)
			max = n;
	} while (res < 0);
	printf("Наибольшее целое решение неравенства: n = %d", max);
}
