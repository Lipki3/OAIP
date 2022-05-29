
#include "Header.h"
int main() {
	struct bank* client = NULL;
	while (1) {
		switch (menu()) {
		case 1:
			add(&client);
			break;
		case 2:
			print(client, 0);
			break;
		case 3:
			delete(&client);
			break;
		case 4:
			search(client);
			break;
		case 5:
			write(client);
			break;
		case 6:
			read(&client);
			break;
		case 7:
			clear(&client);
			return 0;
		default:
			printf("Error!\n");
			system("CLS");
		}
	}
}