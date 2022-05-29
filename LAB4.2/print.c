#include "Header.h"

void print(struct bank* client, int flag)
{
	if (!client) {
		printf("Stack is empty\n");
		return;
	}

	printf("|          Surname         |  Passport  |    Deposit   |       Account      |\n");
	printf("|---------------------------------------------------------------------------|\n");
	if (flag == 1) {
		if (client->flag == 1) 
			printf("|\t%-19s|\t%-8d|\t%-7s|\t%-12s|\n", client->surname, client->passport, "", client->info.account);
		else 
			printf("|\t%-19s|\t%-8d|\t%-7d|\t%-12s|\n", client->surname, client->passport, client->info.deposit, "");
		client = client->next;
	}
	else {
		do {
			if (client->flag == 1) 
				printf("|\t%-19s|\t%-8d|\t%-7s|\t%-12s|\n", client->surname, client->passport, "", client->info.account);
			else 
				printf("|\t%-19s|\t%-8d|\t%-7d|\t%-12s|\n", client->surname, client->passport, client->info.deposit, "");
			client = client->next;
		} while (client);
	}
	printf("\n\n");
}