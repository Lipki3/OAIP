#include "Header.h"

void delete(struct bank** client) {
	if (!client) {
		printf("Stack is empty\n");
		return;
	}
	int choice = 0; int i;
	system("CLS");
	print(*client, 0);
	printf("Enter number you want to delete: ");
	while (!scanf_s("%d", &choice) || (choice < 1)) {
		printf("Error!\n");
		rewind(stdin);
	}
	if (choice == 0) 
		return;
	choice--;
	struct bank* temp, * del, * root;
	if (choice != 0) {
		root = *client;
		for (i = 0; i < choice - 1; i++) 
			*client = (*client)->next;
		temp = *client;
		*client = (*client)->next;
		del = *client;
		temp->next = del->next;
		*client = root;
	}
	else {
		del = *client;
		*client = (*client)->next;
	}
	free(del);
	system("CLS");
}