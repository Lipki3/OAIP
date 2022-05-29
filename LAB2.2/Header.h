#pragma once
#ifndef MY_H
#define MY_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct bank {
    int flag;
    char surname[16];
    int passportNumber;
    union accountNumber {
        char string[7];
       int  depositAmount;
    }u;
} bank;

void menu(struct bank* list, int clientNumber);
void clearStdin();



#endif

