#include "Header.h"


int menu() {
	int choice;
	printf("1 - Add client\n2 - Show list\n3 - Delete clients\n4 - Search clients\n5 - Write to the file\n6 - Read from file\n7 - Exit\n");
	while (!scanf_s("%d", &choice) || choice < 1 || choice>7) {
		printf("Error!\n");
		rewind(stdin);
	}
	system("CLS");
	return choice;
}