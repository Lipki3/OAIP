#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

struct bank {
	char surname[20];
	int passport;
	union Info {
		char account[10];
		int deposit;
	} info;
	int flag;
	struct bank* next;
};

int menu();
void add(struct bank**, struct bank**);
void print(struct bank*, int);
void delete(struct bank**, struct bank**);
void search(struct bank*);
void writeText(struct bank*);
void write(struct bank*);
void writeBin(struct bank*);
void read(struct bank**, struct bank**);
void readText(struct bank**, struct bank**);
void readBin(struct bank**, struct bank**);
void alignment(struct bank*);
void clear(struct bank**, struct bank**);
