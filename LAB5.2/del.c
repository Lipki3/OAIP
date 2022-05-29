#include "Header.h"

void delete(struct bank** head, struct bank** tail) {
	if (!head) {
		printf("Stack is empty\n");
		return;
	}
	int choice = 0;
	system("CLS");
	print(*head, 0);
	printf("\n\n");
	printf("Enter number you want to delete: ");
	while (!scanf_s("%d", &choice) || (choice < 0)) {
		printf("Error!\n");
		rewind(stdin);
	}
	if (choice == 0)
		return;
	choice--;
	if (*head == *tail) {
		free(*tail);
		*head = *tail = NULL;
		system("CLS");
		return;
	}
	struct bank* prev, * current, * pbeg; int i;
	if (choice != 0) {
		pbeg = *head;
		for (i = 0; i < choice - 1; i++)
			*head = (*head)->next;
		prev = *head;
		*head = (*head)->next;
		current = *head;
		prev->next = current->next;
		*head = pbeg;
	}
	else {
		current = *head;
		*head = (*head)->next;
	}
	free(current);
	prev = *head;
	while (prev->next) 
		prev = prev->next;
	*tail = prev;
	system("CLS");
}