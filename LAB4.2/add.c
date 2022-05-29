#include "Header.h"

void add(struct bank** client) {
	system("CLS");
	struct bank* temp = *client;
		if (!(*client = (struct bank*)calloc(1, sizeof(struct bank)))) {
			puts("Not enough memory!\n");
			return;
		}
		printf("Enter surname: ");
		rewind(stdin);
		fgets((*client)->surname, 20, stdin);
		rewind(stdin);
		printf("Enter passport number: ");
		while (!scanf_s("%d", &(*client)->passport) || ((*client)->passport < 1)) {
			rewind(stdin);;
			printf("Error\n");
		}
		printf("\n1 - Enter acccount number\n2 - Enter deposit amount\n ");
		while (!scanf_s("%d", &(*client)->flag) || ((*client)->flag < 1) || ((*client)->flag > 2)) {
			rewind(stdin);
			printf("Error\n");
		}
		if ((*client)->flag == 1) {
			printf("Enter account number: ");
			rewind(stdin);
			fgets((*client)->info.account, 10, stdin);
			rewind(stdin);
		}
		else {
			printf("Enter deposit amount: ");
			while (!scanf_s("%d", &(*client)->info.deposit) || ((*client)->info.deposit < 1))  {
				rewind(stdin);
				printf("Error!\n");
			}
		}
		alignment(*client);
		(*client)->next = temp;
		temp = *client;
		system("CLS");
		rewind(stdin);
}