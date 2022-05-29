#include <stdio.h>
#include <locale.h>
#include <math.h>
int main()
{
    setlocale(LC_ALL, "Rus");
    float x, y1, y2, y3, a;
    printf("Введите число x \n");
    while ((scanf_s("%f", &x) != 1))
    {
        printf("ОШИБКА! Вы ввели не число!\n");
        rewind(stdin);
        printf("Введите число!\n");
    }
        y1 = x - 0.5;
        y2 = 3 * pow(x, 2) - 0.1;
        y3 = 0.2 * pow(x, 2) - 0.3 * x;
        a = 2 * pow(y1, 3) - 1.5 * y3 + 0.7 * y2;
        printf("Результат: %f", a);
        return 0;
}
