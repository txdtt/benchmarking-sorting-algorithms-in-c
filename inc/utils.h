#ifndef UTILS_H
#define UTILS_H

#ifdef _WIN32
    #define CLR_SCREEN system("cls");
    #define WAIT_INPUT system("pause");
#else
    #include <stdlib.h>
    #define CLR_SCREEN system("clear");
    #define WAIT_INPUT system("pause");
#endif

void welcome_msg();

// Verifica se o programa deve reiniciar
int* restart(int *retry);

// Fecha o programa
int exit_program();

#endif