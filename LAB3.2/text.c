#include "Header.h"
void text() {
	int choice = 0; int i, p, k; int* numbers;  int* even;
	int size;
	FILE* file;
	printf("Enter size:");
	while (!scanf("%d", &size) || size < 1) {
		printf("\nError!\n");
		rewind(stdin);
	}
	numbers = (int*)malloc(size * sizeof(int));
	even = (int*)malloc(size * sizeof(int));
	even = numbers;
	do {
		printf("\n1 - Enter numbers\n2 - Print even numbers\n3 - Multiply the first two numbers\n4 - Exit\n");
		while (!scanf("%d", &choice) || choice > 4 || choice < 1) {
			printf("\nError!\n");
			rewind(stdin);
		}
		clearStdin();
		switch (choice) {
		case 1:
			
			file = fopen("text.txt", "w");
			printf("Enter numbers:\n ");
			for (i = 0; i < size; i++)
				scanf_s("%d", &numbers[i]);
			for (i = 0; i < size; i++)
				fprintf(file, "%d ", numbers[i]);
			fprintf(file, " \n\n\n");
			fclose(file);
			printf("\nFile: ");
			file = fopen("text.txt", "r");
			k = numbers[0];
			for (i = 0; i < size; i++) {
					if (fscanf(file, "%d", numbers)) {
						printf("%d ", numbers[i]);
					}
					numbers[0] = k;
			}

			break;
		case 2:
			file = fopen("text.txt", "r");
			printf("\nEven numbers: ");
			for (i = 0; i < size; i++) {
				while (!feof(file)) {
					if (fscanf(file, "%d", even) > 0) {
						if (even[i] % 2 == 0)
							printf("%d ", even[i]);
					}
				}
			}
			numbers[0] = k;
			//printf("\n numbers0 = %d", numbers[0]);
			fclose(file);

			break;
		case 3:
			multiple(numbers);
			break;
		case 4:
			break;
		}
	} while (choice != 4);
}