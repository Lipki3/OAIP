#include "Header.h"

void menu(struct cinema* list, int filmNumber) {
    int i, j;  int choice = 0;  int filmnumber = 0; int numberOfFilms = 0; int numberToDelete;  cinema vvoid = { 0 }; int finder = 0; char* findByTitle;
    int flag = 0; int changer = 0; int changeFilm; int sorter; char* string; char* findString = NULL; 
    string = (char*)malloc(30);
    finder = (char*)malloc(30);
    findByTitle = (char*)malloc(30);
    do {
        printf("\n1 - Add film\n2 - Show films\n3 - Change film\n4 - Find film\n5 - Sort films\n"
            "6 - Delete film \n7 - Partial match search\n8 - Quit \n\n");
        while (!scanf_s("\n%d", &choice) || choice > 8 || choice < 1) {
            printf("\nError!\n");
            rewind(stdin);
        }
        clearStdin();
        switch (choice) {
        case 1:
            if (filmNumber < 30) {
                printf("Enter film title: ");
                gets(list[filmNumber].filmTitle);
                printf("\nEnter film session: ");
                while (!scanf_s("%d", &list[filmNumber].filmSession) || list[filmNumber].filmSession < 1) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                printf("\nEnter ticket price: ");
                while (!scanf_s("%d", &list[filmNumber].ticketPrice) || list[filmNumber].ticketPrice < 1) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                printf("\nEnter number of viewers: ");
                while (!scanf_s("%d", &list[filmNumber].numberOfViewers) || list[filmNumber].numberOfViewers < 0) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                filmNumber++; numberOfFilms++;
            }
            else printf("Full");
            break;
        case 2:
            printf("|-------- Film title --------| Film session | Ticket price | Number of viewers | \n");
            for (filmNumber = 0; filmNumber < numberOfFilms; filmNumber++) {
                printf("                             |              |              |                   |\r");
                printf("                             |              |              |       "
                    "%d\r", list[filmNumber].numberOfViewers);
                printf("                             |              |     "
                    "%d\r", list[filmNumber].ticketPrice);
                printf("                             |      "
                    "%d\r", list[filmNumber].filmSession);
                printf("| ");
                printf("%s", list[filmNumber].filmTitle);
                printf("\n");
            }
            printf("\n\n");
            break;
        case 3:
            printf("\n31 - Change film title\n32 - Change film session\n33 - Change ticket price\n34 - Change number of viewers\n");
            while (!scanf_s("%d", &changeFilm) || changeFilm < 31 || changeFilm > 34) {
                printf("\nError!\n");
                rewind(stdin);
            }
            printf("\nEnter the number of the film you want to change: ");
            while (!scanf_s("%d", &changer) || changer < 1 || changer > numberOfFilms) {
                printf("\nError!\n");
                rewind(stdin);
            }
            switch (changeFilm) {
            case 31:
                printf("Enter new film title: ");
                fseek(stdin, 0, SEEK_SET);
                gets(list[changer - 1].filmTitle);


                break;
            case 32:
                printf("\nEnter new film session: ");
                while (!scanf_s("%d", &list[changer - 1].filmSession) || list[changer - 1].filmSession < 1) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                break;
            case 33:
                printf("\nEnter new ticket price: ");
                while (!scanf_s("%d", &list[changer - 1].ticketPrice) || list[changer - 1].ticketPrice < 1) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                break;
            case 34:
                printf("\nEnter new number of viewers: ");
                while (!scanf_s("%d", &list[changer - 1].numberOfViewers) || list[changer - 1].numberOfViewers < 0) {
                    printf("\nError!\n");
                    rewind(stdin);
                }
                break;
            }
            break;

        case 4:
            printf("\n41 - Find by title\n42 - Find by film session\n43 - Find by ticket price\n44 - Find by number of viewers\n");
            while (!scanf_s("\n%d", &finder) || finder < 41 || finder>44) {
                printf("\nError!");
                rewind(stdin);
            }
            switch (finder) {
            case 41:
                printf("Enter film title: ");
                fseek(stdin, 0, SEEK_SET);
                gets(findByTitle);
                for (i = 0; i < numberOfFilms; i++) {
                    if (strcmp(findByTitle, list[i].filmTitle) == 0) {
                        printf("\nFilm: %s\nFilm session: %d\nTicket price: %d\nNumber of viewers: %d\n\n", list[i].filmTitle, list[i].filmSession, list[i].ticketPrice, list[i].numberOfViewers);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            case 42:
                printf("\nEnter film session: ");
                while (!scanf_s("%d", &finder) || finder < 1) {
                    printf("\nError\n");
                    rewind(stdin);
                }
                for (i = 0; i < numberOfFilms; i++) {
                    if (list[i].filmSession == finder) {
                        printf("\nFilm: %s\nFilm session: %d\nTicket price: %d\nNumber of viewers: %d\n\n", list[i].filmTitle, list[i].filmSession, list[i].ticketPrice, list[i].numberOfViewers);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            case 43:
                printf("\nEnter ticket price: ");
                while (!scanf_s("%d", &finder) || finder < 1) {
                    printf("\nError\n");
                    rewind(stdin);
                }
                for (i = 0; i < numberOfFilms; i++) {
                    if (list[i].ticketPrice == finder) {
                        printf("\nFilm: %s\nFilm session: %d\nTicket price: %d\nNumber of viewers: %d\n\n", list[i].filmTitle, list[i].filmSession, list[i].ticketPrice, list[i].numberOfViewers);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            case 44:
                printf("\nEnter number of viewers: ");
                while (!scanf_s("%d", &finder) || finder < 0) {
                    printf("\nError\n");
                    rewind(stdin);
                }
                for (i = 0; i < numberOfFilms; i++) {
                    if (list[i].numberOfViewers == finder) {
                        printf("\nFilm: %s\nFilm session: %d\nTicket price: %d\nNumber of viewers: %d\n\n", list[i].filmTitle, list[i].filmSession, list[i].ticketPrice, list[i].numberOfViewers);
                        flag = 1;
                    }
                }
                if (flag == 0)
                    printf("No matches found\n\n");
                flag = 0;
                break;
            }
            break;
        case 5:
            printf("15 - Sort Ascending\n16 - Sort descending\n");
            while (!scanf_s("\n%d", &sorter) || sorter < 15 || sorter > 16) {
                printf("\nError!");
                rewind(stdin);
            }
            switch (sorter) {
            case 15:
                printf("\n51 - Sort by title\n52 - Sort by film session\n53 - Sort by ticket price\n54 - Sort by number of viewers\n");
                while (!scanf_s("\n%d", &sorter) || sorter < 51 || sorter>54) {
                    printf("\nError!");
                    rewind(stdin);
                }
                switch (sorter) {
                case 51:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (strcmp(list[j - 1].filmTitle, list[j].filmTitle) > 0)
                            {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 52:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].filmSession < list[j - 1].filmSession) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 53:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].ticketPrice < list[j - 1].ticketPrice) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 54:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].numberOfViewers < list[j - 1].numberOfViewers) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                }
                break;
            case 16:
                printf("\n51 - Sort by title\n52 - Sort by film session\n53 - Sort by ticket price\n54 - Sort by number of viewers\n");
                while (!scanf_s("\n%d", &sorter) || sorter < 51 || sorter>54) {
                    printf("\nError!");
                    rewind(stdin);
                }
                switch (sorter) {
                case 51:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (strcmp(list[j].filmTitle, list[j - 1].filmTitle) > 0)
                            {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 52:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].filmSession > list[j - 1].filmSession) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 53:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].ticketPrice > list[j - 1].ticketPrice) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                case 54:
                    for (i = 0; i < numberOfFilms - 1; i++) {
                        for (j = numberOfFilms - 1; j > i; j--) {
                            if (list[j].numberOfViewers > list[j - 1].numberOfViewers) {
                                vvoid = list[j];
                                list[j] = list[j - 1];
                                list[j - 1] = vvoid;
                            }
                        }
                    }
                    break;
                }
                break;
            }
            break;
        case 6:
            printf("\n17- Delete film (or all films) by number in the list\n18 - Delete film by criteria\n");
            while (!scanf_s("\n%d", &finder) || finder < 17 || finder>18) {
                printf("\nError!");
                rewind(stdin);
            }
            switch (finder) {
            case 17:
                printf("Enter the number of the film you want to delete. To delete all films enter %d: ", numberOfFilms + 1);
                while (!scanf_s("%d", &numberToDelete) || numberToDelete<1 || numberToDelete > numberOfFilms + 1) {
                    printf("\Error!\n");
                    rewind(stdin);
                }
                j = numberOfFilms;
                if (numberToDelete != numberOfFilms + 1) {
                    for (i = numberToDelete - 1; i < numberOfFilms; i++) {
                        list[i] = list[i + 1];
                    }
                    numberOfFilms--;
                }
                else {
                    for (i = 0; i < numberOfFilms; i++)
                        list[i] = vvoid;
                    numberOfFilms = 0;
                    filmNumber = 0;
                }
                break;
            case 18:
                printf("\n61 - Delete by title\n62 - Delete by film session\n63 - Delete by ticket price\n64 - Delete by number of viewers\n");
                while (!scanf_s("\n%d", &finder) || finder < 61 || finder>64) {
                    printf("\nError!");
                    rewind(stdin);
                }
                switch (finder) {
                case 61:
                    printf("Enter film title: ");
                    fseek(stdin, 0, SEEK_SET);
                    gets(findByTitle);
                    for (i = 0; i < numberOfFilms; i++) {
                        if (strcmp(findByTitle, list[i].filmTitle) == 0) {
                            for (i; i < numberOfFilms; i++) {
                                list[i] = list[i + 1];
                            }
                            numberOfFilms--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    break;
                case 62:
                    printf("\nEnter film session: ");
                    while (!scanf_s("%d", &finder) || finder < 1) {
                        printf("\nError\n");
                        rewind(stdin);
                    }
                    for (i = 0; i < numberOfFilms; i++) {
                        if (finder == list[i].filmSession) {
                            for (i; i < numberOfFilms; i++) {
                                list[i] = list[i + 1];
                            }
                            numberOfFilms--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    break;
                case 63:
                    printf("\nEnter ticket price: ");
                    while (!scanf_s("%d", &finder) || finder < 1) {
                        printf("\nError\n");
                        rewind(stdin);
                    }
                    for (i = 0; i < numberOfFilms; i++) {
                        if (finder == list[i].ticketPrice) {
                            for (i; i < numberOfFilms; i++) {
                                list[i] = list[i + 1];
                            }
                            numberOfFilms--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    break;
                case 64:
                    printf("\nEnter number of viewers: ");
                    while (!scanf_s("%d", &finder) || finder < 0) {
                        printf("\nError\n");
                        rewind(stdin);
                    }
                    for (i = 0; i < numberOfFilms; i++) {
                        if (finder == list[i].numberOfViewers) {
                            for (i; i < numberOfFilms; i++) {
                                list[i] = list[i + 1];
                            }
                            numberOfFilms--;
                            flag = 1;
                        }
                    }
                    if (flag == 0)
                        printf("No matches found\n\n");
                    flag = 0;
                    break;
                }
                break;
            } 
            break;
        case 7:
            printf("Enter film title: ");
            fseek(stdin, 0, SEEK_SET);
            gets(string);
            flag = 0;
            for (i = 0; i < numberOfFilms; i++) {
            findString = strstr(list[i].filmTitle, string);
                if (findString != NULL) {
                   printf("\nFilm: %s\nFilm session: %d\nTicket price: %d\nNumber of viewers: %d\n\n", list[i].filmTitle, list[i].filmSession, list[i].ticketPrice, list[i].numberOfViewers);
                   flag = 1;
                }
            }
            if (flag == 0)
                printf("No films found\n");
            break;
        case 8:
            break;
        }
    } while (choice != 8);

}

void clearStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}