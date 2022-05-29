#include "Header.h"

void menu(struct bank* list, int clientNumber) {
    int i, j;  int choice = 0; int numberOfClients = 0; int numberToDelete;  bank vvoid = { 0 }; int finder = 0; char* findByString;
    int flag = 0; char* string; char* findString = NULL; int max; 
    string = (char*)malloc(16);
    finder = (int*)malloc(16 * sizeof(int));
    findByString = (char*)malloc(16);
    do {
        printf("\n1 - Add client\n2 - Show clients\n4 - Find client\n"
            "6 - Delete client \n7 - Partial match search\n8 - Quit  \n\n");
        while (!scanf_s("\n%d", &choice) || choice > 9 || choice < 1) {
            printf("\nError!\n");
            rewind(stdin);
        }
        clearStdin();
        switch (choice) {
        case 1:
            list = (bank*)realloc(list, (numberOfClients + 1) * sizeof(bank));
            printf("Enter client's surname: ");
            rewind(stdin);
            gets(list[clientNumber].surname);
            printf("\nEnter number of passport: ");
            while (!scanf_s("%d", &list[clientNumber].passportNumber) || list[clientNumber].passportNumber < 1000000 || list[clientNumber].passportNumber > 9999999) {
                printf("\nError!\n");
                rewind(stdin);
            }
            printf("11 - Enter account number, 12 - Enter deposit amount\n");
            while (!scanf_s("%d", &finder) || finder < 11 || finder>12); {
                rewind(stdin);
            }
            switch (finder) {
            case 11:
                list[clientNumber].flag = 1;
                rewind(stdin);
                while (!gets(list[clientNumber].u.string)) {
                    printf("\nError!");
                    rewind(stdin);
                }
                break;
            case 12:
                rewind(stdin);
                list[clientNumber].flag = 2;
                while (!scanf_s("%d", &list[clientNumber].u.depositAmount) || list[clientNumber].u.depositAmount < 0) {
                    printf("\nError");
                    rewind(stdin);
                }
                  
            }
            clientNumber++; numberOfClients++;
            break;
        case 2:
            printf("|---- Surname ----| Passport number | Account number | Deposit amount |");
            for (clientNumber = 0; clientNumber < numberOfClients; clientNumber++)
            {
                printf("\n");
                if (list[clientNumber].flag == 1)
                {
                    printf("| %-16s|     %-12d| %-15s|                |", list[clientNumber].surname, list[clientNumber].passportNumber, list[clientNumber].u.string);
                }
                else
                {
                    printf("| %-16s|     %-12d|                | %-14d |", list[clientNumber].surname, list[clientNumber].passportNumber, list[clientNumber].u.depositAmount);
                }
            }
            break;


        case 4:
            printf("\n41 - Find by surname\n42 - Find by passport number\n43 - Find by account number\n44 - Find by deposit amount\n");
            while (!scanf_s("\n%d", &finder) || finder < 41 || finder>44) {
                printf("\nError!");
                rewind(stdin);
            }
            switch (finder) {
            case 41:
                printf("Enter surname: ");
                fseek(stdin, 0, SEEK_SET);
                gets(findByString);
                for (i = 0; i < numberOfClients; i++) {
                    if (strcmp(findByString, list[i].surname) == 0) {
                        if (list[i].flag == 1)
                            printf("\nSurname: %s\nPassport number: %d\nAccount number: %s\n\n", list[i].surname, list[i].passportNumber, list[i].u.string);
                        else
                            printf("\nSurname: %s\nPassport number: %d\nDeposit amount: %d\n\n", list[i].surname, list[i].passportNumber, list[i].u.depositAmount);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            case 42:
                printf("\nEnter passport number: ");
                while (!scanf_s("%d", &finder) || finder < 1000000 || finder > 9999999) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                for (i = 0; i < numberOfClients; i++) {
                    if (list[i].passportNumber == finder) {
                        if (list[i].flag == 1)
                            printf("\nSurname: %s\nPassport number: %d\nAccount number: %s\n\n", list[i].surname, list[i].passportNumber, list[i].u.string);
                        else
                            printf("\nSurname: %s\nPassport number: %d\nDeposit amount: %d\n\n", list[i].surname, list[i].passportNumber, list[i].u.depositAmount);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            case 43:
                printf("\nEnter account number: ");
                fseek(stdin, 0, SEEK_SET);
                gets(findByString);
                for (i = 0; i < numberOfClients; i++) {
                    if (strcmp(findByString, list[i].u.string) == 0) {
                        if (list[i].flag == 1)
                            printf("\nSurname: %s\nPassport number: %d\nAccount number: %s\n\n", list[i].surname, list[i].passportNumber, list[i].u.string);
                        else
                            printf("\nSurname: %s\nPassport number: %d\nDeposit amount: %d\n\n", list[i].surname, list[i].passportNumber, list[i].u.depositAmount);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;

                break;
            case 44:
                printf("\nEnter deposit amount: ");
                while (!scanf_s("%d", &finder)) {
                    printf("\nError");
                    rewind(stdin);
                }
                for (i = 0; i < numberOfClients; i++) {
                    if (list[i].u.depositAmount == finder) {
                        if (list[i].flag == 1)
                            printf("\nSurname: %s\nPassport number: %d\nAccount number: %s\n\n", list[i].surname, list[i].passportNumber, list[i].u.string);
                        else
                            printf("\nSurname: %s\nPassport number: %d\nDeposit amount: %d\n\n", list[i].surname, list[i].passportNumber, list[i].u.depositAmount);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;

            }

            break;

        case 6:
            printf("\n17- Delete by number in the list\n18 - Delete by criteria\n");
            while (!scanf_s("\n%d", &finder) || finder < 17 || finder>18) {
                printf("\nError!");
                rewind(stdin);
            }
            switch (finder) {
            case 17:
                printf("Enter the number you want to delete. To delete all enter %d: ", numberOfClients + 1);
                while (!scanf_s("%d", &numberToDelete) || numberToDelete<1 || numberToDelete > numberOfClients + 1) {
                    printf("\Error!\n");
                    rewind(stdin);
                }
                j = numberOfClients;
                if (numberToDelete != numberOfClients + 1) {
                    for (i = numberToDelete - 1; i < numberOfClients; i++) {
                        list[i] = list[i + 1];
                    }
                    numberOfClients--;
                    list = (bank*)realloc(list, (numberOfClients) * sizeof(bank));
                }
                else {
                    for (i = 0; i < numberOfClients; i++)
                        list[i] = vvoid;
                    numberOfClients = 0;
                    clientNumber = 0;
                    list = (bank*)realloc(list, 0);
                }
                break;
            case 18:
                printf("\n61 - Delete by surname\n62 - Delete by passport number\n63 - Delete by account number\n64 - Delete by deposit amount\n");
                while (!scanf_s("\n%d", &finder) || finder < 61 || finder>64) {
                    printf("\nError!");
                    rewind(stdin);
                }
                switch (finder) {
                case 61:
                    printf("Enter surname: ");
                    fseek(stdin, 0, SEEK_SET);
                    gets(findByString);
                    for (i = 0; i < numberOfClients; i++) {
                        if (strcmp(findByString, list[i].surname) == 0) {
                            for (i; i < numberOfClients; i++) {
                                list[i] = list[i + 1];
                            }
                            numberOfClients--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    list = (bank*)realloc(list, (numberOfClients) * sizeof(bank));
                    break;
                case 62:
                    printf("\nEnter passport number: ");
                    while (!scanf_s("%d", &finder) || finder < 1000000 || finder > 9999999) {
                        printf("\nError!\n");
                        rewind(stdin);
                    }
                    for (i = 0; i < numberOfClients; i++) {
                        if (finder == list[i].passportNumber) {
                            j = i;
                            for (j; j < numberOfClients; j++)
                                list[j] = list[j + 1];
                            numberOfClients--;
                            flag = 1;
                            i--;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    list = (bank*)realloc(list, (numberOfClients) * sizeof(bank));
                    break;
                case 63:
                    printf("\nEnter account number: ");
                    fseek(stdin, 0, SEEK_SET);
                    gets(findByString);
                    for (i = 0; i < numberOfClients; i++) {
                        if (strcmp(findByString, list[i].u.string) == 0) {
                            j = i;
                            for (j; j < numberOfClients; j++) {
                                list[j] = list[j + 1];
                            }
                            i--;
                            numberOfClients--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    list = (bank*)realloc(list, (numberOfClients) * sizeof(bank));
                    break;
                case 64:
                    printf("\nEnter deposit amount: ");
                    while (!scanf_s("%d", &finder)) {
                        printf("\nError");
                        rewind(stdin);
                    }
                   
                    for (i = 0; i < numberOfClients; i++) {
                        if (list[i].u.depositAmount == finder) {
                            j = i;
                            for (j; j < numberOfClients; j++) {
                                list[j] = list[j + 1];
                            }
                            numberOfClients--;
                            flag = 1;
                            i--;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    list = (bank*)realloc(list, (numberOfClients) * sizeof(bank));
                }
                break;
            }
            break;
        case 7:
            printf("Enter surname: ");
            fseek(stdin, 0, SEEK_SET);
            gets(string);
            flag = 0;
            for (i = 0; i < numberOfClients; i++) {
                findString = strstr(list[i].surname, string);
                if (findString != NULL) {
                    if (list[i].flag == 1)
                        printf("\nSurname: %s\nPassport number: %d\nAccount number: %s\n\n", list[i].surname, list[i].passportNumber, list[i].u.string);
                    else
                        printf("\nSurname: %s\nPassport number: %d\nDeposit amount: %d\n\n", list[i].surname, list[i].passportNumber, list[i].u.depositAmount);
                    flag = 1;
                }
            }
            if (flag == 0)
                printf("No matches found\n");
            break;
        
        case 8:
            break;
        }
    } while (choice != 9);
         
    free (string);
    free(findByString);
    free(list);
    
}

void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}