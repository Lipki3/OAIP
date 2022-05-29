#include "Header.h"

void menu(struct tree** root) {
	int choice = 0;
	do  {
		printf("1 - Add word\n2 - Show words\n3 - Delete\n4 - Write to file\n5 - Exit\n");
		while (!scanf("%d", &choice) || choice > 5 || choice < 1) {
			rewind(stdin);
			printf("Error\n");
		}
		system("CLS");
		switch (choice) {
		case 1:
			add(&root);
			break;
		case 2:
			print(root);
			break;
		case 3:
			del(&root);
			break;
		case 4:
			file(root);
			break;
		case 5:
			clean(&root);
			return 0;
		}
	} while (choice != 5);
}