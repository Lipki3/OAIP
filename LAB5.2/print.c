
#include "Header.h"



void print(struct bank* head, int flag)
{
	if (!head) {
		printf("Stack is empty\n");
		return;
	}
	printf("|          Surname         |  Passport  |    Deposit   |       Account      |\n");
	printf("|---------------------------------------------------------------------------|\n");

	if (flag == 1) {
		if (head->flag == 1)
			printf("|\t%-19s|\t%-8d|\t%-7s|\t%-12s|\n", head->surname, head->passport, "", head->info.account);
		else
			printf("|\t%-19s|\t%-8d|\t%-7d|\t%-12s|\n", head->surname, head->passport, head->info.deposit, "");
		head = head->next;
	}
	else {
		do {
			if (head->flag == 1)
				printf("|\t%-19s|\t%-8d|\t%-7s|\t%-12s|\n", head->surname, head->passport, "", head->info.account);
			else
				printf("|\t%-19s|\t%-8d|\t%-7d|\t%-12s|\n", head->surname, head->passport, head->info.deposit, "");
			head = head->next;
		} while (head);
	}
	printf("\n\n");
}