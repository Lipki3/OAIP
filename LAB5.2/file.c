#include "Header.h"

void write(struct bank* head) {
	if (!head) {
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
		writeText(head);
		break;
	case 2:
		writeBin(head);
		break;
	}
}


void writeText(struct bank* head) {
	FILE* f = fopen("file.txt", "w");
	do {
		if (head->flag == 1)
			fprintf(f, "Flag: %d\nPassport: %d\nAccount: %s\nSurname: %s\n\n", head->flag, head->passport, head->info.account, head->surname);
		else
			fprintf(f, "Flag: %d\nPassport: %d\nDeposit: %d\nSurname: %s\n\n", head->flag, head->passport, head->info.deposit, head->surname);
		head = head->next;
	} while (head);
	fclose(f);
	system("CLS");
}


void writeBin(struct bank* head) {
	FILE* f = fopen("file1.bin", "wb");
	do {
		if (head->flag == 1) {
			fwrite(head->surname, 20, 1, f);
			fwrite(&(head->flag), sizeof(int), 1, f);
			fwrite(&(head->passport), sizeof(int), 1, f);
			fwrite(head->info.account, strlen(head->info.account), 1, f);
		}
		else {
			fwrite(head->surname, 20, 1, f);
			fwrite(&(head->flag), sizeof(int), 1, f);
			fwrite(&(head->passport), sizeof(int), 1, f);
			fwrite(&(head->info.deposit), sizeof(int), 1, f);
		}
		head = head->next;
	} while (head);
	fclose(f);
	system("CLS");
}


void read(struct bank** head, struct bank** tail) {
	printf("1 - Text file\n2 - Bin file\n");
	int choice;
	while (!scanf_s("%d", &choice) || (choice < 1) || (choice > 2)) {
		printf("Error!.\n");
		rewind(stdin);
	}
	switch (choice) {
	case 1:
		readText(head, tail);
		break;
	case 2:
		readBin(head, tail);
		break;
	}
}


void readText(struct bank** head, struct bank** tail) {
	system("CLS");
	FILE* f = fopen("file.txt", "r");
	struct bank* temp;
	do {
		if (feof(f)) break;
		if (!(temp = (struct bank*)calloc(1, sizeof(struct bank)))) {
			printf("Not enough memory!\n");
			return;
		}
		fscanf(f, "%d", &temp->flag);
		fseek(f, 1, SEEK_CUR);
		fscanf(f, "%d", &temp->passport);
		fseek(f, 1, SEEK_CUR);
		if (temp->flag == 1)
			fgets(temp->info.account, 10, f);
		else {
			fscanf(f, "%d", &temp->info.deposit);
			fseek(f, 1, SEEK_CUR);
		}
		fgets(temp->surname, 20, f);
		alignment(temp);
		if (!*head)
			*tail = *head = temp;
		else {
			(*tail)->next = temp;
			*tail = temp;
		}
		if (feof(f)) break;
	} while (1);
	temp = *head;
	while (*tail != temp->next)
		temp = temp->next;
	*tail = temp;
	(*tail)->next = NULL;
	fclose(f);
}


void readBin(struct bank** head, struct bank** tail) {
	system("CLS");
	FILE* f = fopen("file1.bin", "rb");
	struct bank* temp;
	fpos_t end, pos;
	fseek(f, 0, SEEK_END);
	fgetpos(f, &end);
	rewind(f);
	do {
		if (!(temp = (struct bank*)calloc(1, sizeof(struct bank)))) {
			printf("Not enough memory!\n");
			return;
		}
		fgets(temp->surname, 20, f);
		fseek(f, 1, SEEK_CUR);
		fread(&temp->flag, sizeof(int), 1, f);
		fread(&temp->passport, sizeof(int), 1, f);
		if (temp->flag == 1) {
			fgets(temp->info.account, 9, f);
		}
		else {
			fread(&temp->info.deposit, sizeof(int), 1, f);
		}
		fgetpos(f, &pos);
		if (!*head)
			*tail = *head = temp;
		else {
			(*tail)->next = temp;
			*tail = temp;
		}
		if (pos == end) break;
	} while (1);
	fclose(f);
}