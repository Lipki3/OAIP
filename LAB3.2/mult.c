#include "Header.h"
int multiple(int* numbers) {
	FILE* file;
	if (!(file = fopen("text.txt", "a")))
	{
		puts("\nEror!");
		getch();
		return;
	}
	int mno = numbers[0]; int count = 0; int countMN=0; int countMT=0;
	int mn[10]; int i; int p;
	int c = numbers[0];
	int n = 1;
	p = mno * numbers[1];
	int mnt = mno; int count1;
	int mt = numbers[1];
	int difMN, difMT, difCOUNT;
	do {  // считаем количество цифр произведения
		p = p / 10;
		count++;
	} while (p > 0);
	//printf("%d ", count);
	do {  // считаем количество цифр мн
		mnt = mnt / 10;
		countMN++;
	} while (mnt > 0);
	// printf("%d ", countMN);
	do {  // считаем количество цифр мт
		mt = mt / 10;
		countMT++;
	} while (mt>0);
	// printf("%d ", countMT);
	difMN = count - countMN;
	difMT = count - countMT;
	p = mno * numbers[1];
	do {  
		c = c / 10;
		if (c < 10) {
			c = c % 10;
		}
		n++;
	} while (c > 9);
	mn[0] = c;
	numbers[0] = numbers[0] - c * pow(10, (n - 1));
	//printf("\nn - %d, c - %d, numbers[0] - %d", n, c, numbers[0]);
	for (i = 1; i < n; i++) {
		int c = numbers[0];
		do {

			if (c < 10) {
				c = c % 10;
			}
			else c = c / 10;
		} while (c > 9);
		mn[i] = c;
		numbers[0] = numbers[0] - c * pow(10, (n - i - 1));
	}
	printf("\n");
	for (i = 0; i < difMT; i++)
		printf(" ");
	printf("%d", numbers[1]);
	fprintf(file,"%d", numbers[1]);
	printf("\n*");
	fprintf(file,"\n*\n");
	printf("\n");
	for (i = 0; i < difMN; i++) {
		printf(" ");
		fprintf(file, " ");
	}
	printf("%d", mno);
	fprintf(file, "%d", mno);
	printf("\n");
	fprintf(file, "\n");
	for (i = 0; i < count; i++) {
		printf("-");
		fprintf(file, "-");
	}
	int j = 0;
	for (i = n - 1; i > -1; i--) {
		p = mn[i] * numbers[1];
		int pt = p; count1 = 0;
		do {  // считаем количество цифр произведения
			pt = pt / 10;
			count1++;
		} while (pt > 0);
		difCOUNT = count - count1;
		//printf("\n\ndifCOUNT %d", difCOUNT);
		printf("\n");
		fprintf(file, "\n");
		for (j = 0; j < difCOUNT + i - n + 1; j++) {
			printf(" ");
			fprintf(file, " ");
		}
		printf("%d", p);
		fprintf(file, "%d", p);
		//printf("\n\ncount1 %d", count1);
		count1 = 0;
	}
	printf("\n");
	fprintf(file, "\n");
	for (i = 0; i < count; i++) {
		printf("-");
		fprintf(file, "-");
	}
	p = mno * numbers[1];
	printf("\n%d", p);
	fprintf(file, "\n%d", p);
	return c;
}