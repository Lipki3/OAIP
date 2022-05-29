#include "Header.h"
void clearStdin() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF) {}
}