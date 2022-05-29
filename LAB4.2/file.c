#include "Header.h"

void write(struct bank* client) {
	if (!client) {
		printf("Stack is empty\n");
		return;
	}
	printf("1 - Text file\n2 - Bin file\n");
	int choice;
	while (!scanf_s("%d", &choice) || (choice < 1) || (choice > 2)) {
		printf("Error\n");
		rewind(stdin);
	}
	switch (choice) {
	case 1:
		writeText(client);
		break;
	case 2:
		writeBin(client);
		break;
	}
}


void writeText(struct bank* client) {
	FILE* f = fopen("file.txt", "w");
	do {
		if (client->flag == 1) 
			fprintf(f, "Flag: %d\nPassport: %d\nAccount: %s\nSurname: %s\n\n", client->flag, client->passport, client->info.account, client->surname);
		else 
			fprintf(f, "Flag: %d\nPassport: %d\nDeposit: %d\nSurname: %s\n\n", client->flag, client->passport, client->info.deposit, client->surname);
		client = client->next;
	} while (client);
	fclose(f);
	system("CLS");
}


void writeBin(struct bank* client) {
	FILE* f = fopen("file1.bin", "wb");
	do {
		if (client->flag == 1) {
			fwrite(client->surname, 20, 1, f);
			fwrite(&(client->flag), sizeof(int), 1, f);
			fwrite(&(client->passport), sizeof(int), 1, f);
			fwrite(client->info.account, strlen(client->info.account), 1, f);
		}
		else {
			fwrite(client->surname, 20, 1, f);
			fwrite(&(client->flag), sizeof(int), 1, f);
			fwrite(&(client->passport), sizeof(int), 1, f);
			fwrite(&(client->info.deposit), sizeof(int), 1, f);
		}
		client = client->next;
	} while (client);
	fclose(f);
	system("CLS");
}


void read(struct bank** client) {
	printf("1 - Text file\n2 - Bin file\n");
	int choice;
	while (!scanf_s("%d", &choice) || (choice < 1) || (choice > 2)) {
		printf("Error!.\n");
		rewind(stdin);
	}
	switch (choice) {
	case 1:
		readText(client);
		break;
	case 2:
		readBin(client);
		break;
	}
}


void readText(struct bank** client) {
	system("CLS");
	FILE* f = fopen("file.txt", "r");
	struct bank* temp = *client;
	do {
		if (feof(f)) break;
		if (!(*client = (struct bank*)calloc(1, sizeof(struct bank)))) {
			printf("Not enough memory!\n");
			return;
		}
		fscanf(f, "%d", &(*client)->flag);
		fseek(f, 1, SEEK_CUR);
		fscanf(f, "%d", &(*client)->passport);
		fseek(f, 1, SEEK_CUR);
		if ((*client)->flag == 1)
			fgets((*client)->info.account, 10, f);
		else {
			fscanf(f, "%d", &(*client)->info.deposit);
			fseek(f, 1, SEEK_CUR);
		}
		fgets((*client)->surname, 20, f);
		alignment(*client);
		(*client)->next = temp;
		if (feof(f)) break;
		temp = *client;
	} while (1);
	*client = (*client)->next;
	fclose(f);
}


void readBin(struct bank** client) {
	system("CLS");
	FILE* f = fopen("file1.bin", "rb");
	struct Series* temp = *client;
	fpos_t end, pos;
	fseek(f, 0, SEEK_END);
	fgetpos(f, &end);
	rewind(f);
	do {
		if (!(*client = (struct bank*)calloc(1, sizeof(struct bank)))) {
			printf("Not enough memory!\n");
			return;
		}
		fgets((*client)->surname, 20, f);
		fseek(f, 1, SEEK_CUR);
		fread(&(*client)->flag, sizeof(int), 1, f);
		fread(&(*client)->passport, sizeof(int), 1, f);
		if ((*client)->flag == 1) 
			fgets((*client)->info.account, 9, f);
		else
			fread(&(*client)->info.deposit, sizeof(int), 1, f);
		fgetpos(f, &pos);
		(*client)->next = temp;
		temp = *client;
		if (pos == end) break;
	} while (1);
	fclose(f);
}