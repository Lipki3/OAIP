#include "Header.h"
int main() {
	int choice;
	printf("\n1 - bin, 2 - text\n3 - exit\n");
	while (!scanf_s("%d", &choice) || choice < 1 || choice >3) {
		printf("\nError");
		rewind(stdin);
	}
	switch (choice) {
	case 1:
		bin();
		break;
	case 2:
		text();
		break;

	case 3:
		break;
	}
}
