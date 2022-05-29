#include "Header.h"

int main() {
	struct bank* head = NULL;
	struct bank* tail = NULL;
	while (1) {
		switch (menu()) {
		case 1:
			add(&head, &tail);
			break;
		case 2:
			print(head, 0);
			break;
		case 3:
			delete(&head, &tail);
			break;
		case 4:
			search(head);
			break;
		case 5:
			write(head);
			break;
		case 6:
			read(&head, &tail);
			break;
		case 7:
			clear(&head, &tail);
			return 0;
		default:
			printf("Error!\n");
			system("CLS");
		}
	}
}
