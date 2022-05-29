#include "Header.h"

void add(struct bank** head, struct bank** tail) {
	system("CLS");
	struct bank* temp;
	if (!(temp = (struct bank*)calloc(1, sizeof(struct bank)))) {
		puts("Not enough memory!\n");
		return;
	}
	printf("Enter surname: ");
	rewind(stdin);
	fgets(temp->surname, 20, stdin);
	rewind(stdin);
	printf("Enter passport number: ");
	while (!scanf_s("%d", &temp->passport) || (temp->passport < 1)) {
		rewind(stdin);
		printf("Error\n");
	}
	printf("\n1 - Enter acccount number\n2 - Enter deposit amount\n ");
	while (!scanf_s("%d", &temp->flag) || (temp->flag < 1) || (temp->flag > 2)) {
		rewind(stdin);
		printf("Error!\n");
	}
	if (temp->flag == 1) {
		printf("Enter account number: ");
		rewind(stdin);
		fgets(temp->info.account, 10, stdin);
		rewind(stdin);
	}
	else {
		printf("Enter deposit amount: ");
		while (!scanf_s("%d", &temp->info.deposit) || (temp->info.deposit < 1)) {
			rewind(stdin);
			printf("Error!\n");
		}
	}
	alignment(temp);
	if (!*head)
		*tail = *head = temp;
	else {
		(*tail)->next = temp;
		*tail = temp;
	}
	system("CLS");
	rewind(stdin);
}