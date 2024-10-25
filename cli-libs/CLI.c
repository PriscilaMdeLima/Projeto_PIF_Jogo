// CLI.c
#include <stdio.h>
#include "CLI.h"

void setForeground(const char* color) {
    printf("%s", color);
}

void resetColors() {
    printf("%s", RESET);
}

void clrscr() {
    printf("\e[1;1H\e[2J");
}

