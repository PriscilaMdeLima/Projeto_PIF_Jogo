// CLI.h
#ifndef CLI_H
#define CLI_H

// Definição das cores
#define RESET       "\x1b[0m"
#define BLACK       "\x1b[30m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define MAGENTA     "\x1b[35m"
#define CYAN        "\x1b[36m"
#define WHITE       "\x1b[37m"
#define LIGHTRED    "\x1b[91m"
#define LIGHTGREEN  "\x1b[92m"
#define LIGHTYELLOW "\x1b[93m"
#define LIGHTCYAN   "\x1b[96m"

// Declaração das funções
void setForeground(const char* color);
void resetColors();
void clrscr();

#endif // CLI_H

