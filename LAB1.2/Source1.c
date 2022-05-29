#include "Header.h"

int main() {
    int filmNumber = 0; 
    cinema* list;
    list = (cinema*)malloc(30 * sizeof(cinema));
    menu(list, filmNumber);
    return 0;
}

