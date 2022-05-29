#include "Header.h"

void search(struct bank* client) {
	if (!client) {
		printf("Stack is empty\n");
		return;
	}
	system("CLS");
	printf("Search by:\n1 - surname\n2 - passport number\n3 - account number\n4 - deposit amount\n");
	int choice, finder = 0, flag = 0, j;
	char string[20];
	while (!scanf_s("%d", &choice) || (choice < 1) || (choice > 4)) {
		system("CLS");
		printf("Error!\n");
		rewind(stdin);
	}
	switch (choice) {
	case 1:
		printf("Enter surname: ");
		rewind(stdin);
		fgets(string, 20, stdin);
		string[strlen(string) - 1] = '\0';
		do
		{
			int temp = 0;
			if (strlen(client->surname) == strlen(string))
			{
				for (j = 0; j < strlen(string); j++)
				{
					if (client->surname[j] != string[j])
						break;
					else
						temp++;
					if (temp == strlen(string))
						print(client, 1);
					flag = 1;
				}
			}
			client = client->next;
		} while (client);
		break;
	case 2:
		printf("Enter passport number: ");
		while (!scanf_s("%d", &finder) || (finder < 1)) {
			printf("Error!\n");
			rewind(stdin);
		}
		do {
			if (client->passport == finder) {
				print(client, 1);
				flag = 1;
				break;
			}
			client = client->next;
		} while (client);
		break;
	case 3:
		printf("Enter account number: ");
		rewind(stdin);
		fgets(string, 10, stdin);
		rewind(stdin);
		string[strlen(string) - 1] = '\0';
		do {
			if (client->flag != 1) {
				client = client->next;
				continue;
			}
			int temp = 0;
			if (strlen(client->info.account) == strlen(string)) {
				for (j = 0; j < strlen(string); j++) {
					if (client->info.account[j] != string[j])
						break;
					else
						temp++;
					if (temp == strlen(string))
						print(client, 1);
					flag = 1;
				}
			}
			client = client->next;
		} while (client);
		break;
	case 4:
		printf("Enter deposit amount: ");
		while (!scanf_s("%d", &finder) || (finder < 1)) {
			printf("Error!\n");
			rewind(stdin);
		}
		do {
			if (client->flag != 2) {
				client = client->next;
				continue;
			}
			if (client->info.deposit == finder) {
				print(client, 1);
				flag = 1;
				break;
			}
			client = client->next;
		} while (client);
		break;
	}
	if (flag == 0)
		printf("No matches found\n");
}