#include "Header.h"
void bin() {
	int choice = 0; int i, j, k; int numbers[20]; int buf[20];
	int size; int kol = 1; int flag = 0;
	FILE* file;
	printf("Enter size: ");
	while (!scanf("%d", &size) || size < 1) {
		printf("\nError!\n");
		rewind(stdin);
	}
	do {
		printf("\n1 - File\n2 - Count the number of different numbers\n3 - Reverse elements\n4 - Exit\n");
		while (!scanf("%d", &choice) || choice > 4 || choice < 1) {
			printf("\nError!\n");
			rewind(stdin);
		}
		clearStdin();
		switch (choice) {
		case 1:
			printf("\n1 - Write\n2 - Read\n3 - Return\n");
			while (!scanf("%d", &choice) || choice > 3 || choice < 1) {
				printf("\nError!\n");
				rewind(stdin);
			}
			switch (choice) {
			case 1:
				printf("Enter numbers:\n");
				for (i = 0; i < size; i++)
					scanf_s("%d", &numbers[i]);
				if (!(file = fopen("bin1.bin", "wb")))
				{
					puts("\nEror!");
					getch();
					return;
				}

				else {
					for (i = 0; i < size; i++)
						fprintf(file, "%d\n", numbers[i]);				//запись в файл
				}
				fclose(file);
				break;
			case 2:
				file = fopen("bin1.bin", "rb");
				printf("File: ");
				while (!feof(file)) {
					if(fscanf(file, "%d ", &numbers[i]))
						printf("%d ", numbers[i]);
				}
				fclose(file);
				break;
			case 3:
				break;
			}
			
			break;
		case 2:
			kol = size;
			for (i = 1, k = i - 1; i < size; i++, k++) {
				k = i - 1;
				flag = 0;
				while (k != -1) {
					if (numbers[i] == numbers[k])
						flag = 1;
					k--;
				}
				if (flag != 0)
					kol--;
				//printf("%d flag. \n", flag);
				flag = 0;
			}
			printf("%d different numbers in file.", kol);
			break;
		case 3:
			for (i = 0; i < size; i++) {
				for (j = size - 1; j > i; j--) {
					k = numbers[j];
					numbers[j] = numbers[j - 1];
					numbers[j - 1] = k;
				}
			}

				if (!(file = fopen("bin1.bin", "wb")))
				{
					puts("\nEror!");
					getch();
					return;
				}

				else {
					for (i = 0; i < size; i++)
						fprintf(file, "%d\n", numbers[i]);				//запись в файл
				}
			fclose(file);

			file = fopen("bin1.bin", "rb");
			printf("\nFile: ");
			while (!feof(file)) {
				if (fscanf(file, "%d ", &numbers[i]))
					printf("%d ", numbers[i]);
			}
			fclose(file);
			fclose(file);
		case 4:
			break;
		}
	} while (choice != 4);
	
}