#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    float x, y1, y2, y3, Z;
    printf("������� ����� x \n");
    while ((scanf_s("%f", &x) != 1))
    {
        printf("������! �� ����� �� �����!\n");
        rewind(stdin);
        printf("������� �����!\n");
    }
        y1 = x - 0.5;
        y2 = 3 * pow(x, 2) - 0.1;
        y3 = 0.2 * pow(x, 2) - 0.3 * x;
        Z = 2 * pow(y1, 3) - 1.5 * y3 + 0.7 * y2;
        printf("���������: %f", Z);
        return 0;
}
