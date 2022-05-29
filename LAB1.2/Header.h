#pragma once
#ifndef MY_H
#define MY_H

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct cinema {
    char filmTitle[30];
    int filmSession;
    int ticketPrice;
    int numberOfViewers;
} cinema;

void menu(struct cinema* list, int filmNumber);
void clearStdin();

#endif

