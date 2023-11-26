#include <stdio.h>
#include <stdbool.h>

#include "../inc/utils.h"

void welcome_msg() {
    printf("\e[?25l");

    #ifdef __GNUC__
        printf ("COMPILED ON GCC VERSION %d.%d\n\n", __GNUC__, __GNUC_MINOR__);
    #endif

    printf("------------------------------------------------------------\n");
    printf("| Visualizador de performance para algoritmos de ordenacao |\n");
    printf("------------------------------------------------------------\n\n");
    printf("Este programa realiza um teste de perfomance para 7 tipos diferentes de algoritmos\n");
    printf("de ordenacao, sendo eles: bubble sort, insertion sort, selection sort, shell sort,\n");
    printf("bead sort, quick sort e merge sort. A performance e avaliada a partir de tres criterios:\n");
    printf("numero de comparacoes realizadas, quantidade de trocas realizadas e tempo de execucao.\n");
    printf("O programa aceita vetores de tamanho 1 ate 100000.\n\n\n");

    WAIT_INPUT;
}


int* restart(int *retry) {
    int ch;

    bool loopAgain = false;

    do {
        printf("Testar para novos valores (1 - SIM; 0 - NAO)?\n");
        *retry = fgetc(stdin);
        if (*retry != '1' && *retry != '0') {
            printf("Entrada invalida! Tente novamente\n");
            while ((ch = getchar()) != '\n');
            loopAgain = true;
            continue;
        } else {
            break; 
        }
    } while (loopAgain);

    while ((ch = getchar()) != '\n');

    return retry;
}

int exit_program() {
    CLR_SCREEN;
    exit(0);
    return 0;
}