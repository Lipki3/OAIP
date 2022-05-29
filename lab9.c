#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int perevod(char* st);
int main()
{
    setlocale(LC_ALL, "Rus");
    char** mas;
    int* kol;
    int n;
    printf("Введите количество строк: ");
    scanf_s("%d", &n);
    mas = (char**)malloc(n * sizeof(char*));
    kol = (int*)malloc(n * sizeof(int)); 
    for (int i = 0; i < n; i++)
    {
        printf("Введите количество символов в строке №%d: ", i + 1);
        scanf_s("%d", &kol[i]);
        printf("Введите строку №%d: ", i + 1);
        kol[i] = kol[i] + 2; 
        mas[i] = (char*)malloc(kol[i] * sizeof(char));
        rewind(stdin);
        fgets(mas[i], kol[i], stdin);
        rewind(stdin);
    }
    char *word, *numbers, *words;
    for (int i = 0; i < n; i++)
    {
        word = (char*)calloc(kol[i], sizeof(char));
        numbers = (char*)calloc(kol[i], sizeof(char));
        words = (char*)calloc(kol[i], sizeof(char));
        int sum = 0;
        int dl = 0;
        for (int j = 1; j < kol[i]; j++)
        {
            if (mas[i][j] != ' ')
            {
                word[dl] = mas[i][j];
                dl++;
            }
            else 
            {
                if (word[0] > '9') 
                {
                    if (dl > 3) 
                        strcat(words, word);
                    dl = 0; 
                    memset(word, 0, kol[i]);
                }
                else
                {
                    sum = sum + perevod(word);
                    strcat(numbers, word);
                    strcat(numbers, " ");
                    dl = 0;
                    memset(word, 0, kol[i]);
                }
            }
        }
        printf("Измененная строка №%d: %s%s  \nСумма чисел в строке: %d\n", i+1, numbers, words, sum);
        free(word);
        free(words);
        free(numbers);
    }
    for (int i = 0; i < n; i++)
    {
        free(mas[i]);
    }
    free(mas);
    free(kol);
    return 0;
}
int perevod(char *st)
{
    int n=0, i = 0, znak;
    while (st[i] == ' ')
        i++;
    if (st[i] == '-')
        znak = -1;
    else
        znak = 1;           
    if (st[i] == '-')  
        i++;
    while (st[i] >= 0x30 && st[i] <= 0x39)
    {
        n = n + (st[i] & 0x0F);
        n = n * 10;
        i++;
    }
    n = n / 10;
    return (znak * n);                   
}
