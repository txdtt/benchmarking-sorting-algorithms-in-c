#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#include "../inc/sorting_data.h"
#include "../inc/sorting_algos.h"
#include "../inc/file_io.h"
#include "../inc/utils.h"

#ifdef _WIN32
    #include <windows.h>
    #include <psapi.h>
#endif

SortFunction* get_sorting_algos(SortFunction bufferAlgos[], const char *sortName[]) {
    char selected_sort[SORT_FUNCTIONS], menu_option;
    int i, j = 0;
    bool loop_again = false;

    for (i = 0; i < SORT_FUNCTIONS; i++) {
        selected_sort[i] = ' ';
    }

    do {
        CLR_SCREEN;

        printf("Selecione quais algoritmos serao utilizados: \n");
        printf("\n1 - Quick Sort\t   [%c]\n2 - Merge Sort\t   [%c]\n3 - Shell Sort\t   [%c]\n4 - Insertion Sort [%c]\n5 - Selection Sort [%c]\n6 - Bubble Sort\t   [%c]\n7 - Bead Sort\t   [%c]\n8 - Avancar\n", 
        selected_sort[0], selected_sort[1], selected_sort[2], selected_sort[3], selected_sort[4], selected_sort[5], selected_sort[6]);
        printf("\e[?25h");
        menu_option = getchar();
        switch (menu_option) {
            case '1':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = quick_sort;
                sortName[j] = "QUICK SORT";
                selected_sort[0] = 'X';
                j++;
                loop_again = true;
                continue;
            case '2':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = merge_sort;
                sortName[j] = "MERGE SORT";
                selected_sort[1] = 'X';
                j++;
                loop_again = true;
                continue;
            case '3':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = shell_sort;
                sortName[j] = "SHELL SORT";
                selected_sort[2] = 'X';
                j++;
                loop_again = true;
                continue;
            case '4':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = insertion_sort;
                sortName[j] = "INSERTION SORT";
                selected_sort[3] = 'X';
                j++;
                loop_again = true;
                continue;
            case '5':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = selection_sort;
                sortName[j] = "SELECTION SORT";
                selected_sort[4] = 'X';
                j++;
                loop_again = true;
                continue;
            case '6':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = bubble_sort;
                sortName[j] = "BUBBLE SORT";
                selected_sort[5] = 'X';
                j++;
                loop_again = true;
                continue;
            case '7':
                while ((menu_option = getchar()) != '\n');
                bufferAlgos[j] = bead_sort;
                sortName[j] = "BEAD SORT";
                selected_sort[6] = 'X';
                j++;
                loop_again = true;
                continue;
            case '8':
                loop_again = false;
                break;
            default:
                while ((menu_option = getchar()) != '\n');
                printf("Entrada invalida! Tente novamente\n");
                WAIT_INPUT;
                loop_again = true;
                continue;
        }
    } while (loop_again);

    while ((menu_option = getchar()) != '\n');

    return bufferAlgos;
}

int* get_type_of_array(int *array_to_be_sorted) {
    char menu_option;

    do {
        CLR_SCREEN;

        printf("Escolha o tipo de vetor a ser ordenado:");
        printf("\n1 - Vetor nao ordenado\n2 - Vetor parcialmente ordenado\n3 - Vetor em ordem crescente\n4 - Vetor em ordem decrescente\n");
        printf("\e[?25h");
        menu_option = getchar();
        switch (menu_option) {
            case '1':
                write_file_in_array("res/unsorted_values.txt", array_to_be_sorted);
                break;
            case '2':
                write_file_in_array("res/partially_sorted_values.txt", array_to_be_sorted);
                break;
            case '3':
                write_file_in_array("res/ascending_sorted_values.txt", array_to_be_sorted);
                break;
            case '4':
                write_file_in_array("res/descending_sorted_values.txt", array_to_be_sorted);
                break;
            default:
                while ((menu_option = getchar()) != '\n');
                printf("Entrada invalida! Tente novamente\n");
                WAIT_INPUT;
                continue;
        }
    } while (menu_option != '1' && menu_option != '2' && menu_option != '3' && menu_option != '4');

    while ((menu_option = getchar()) != '\n');

    return array_to_be_sorted;
}

int* write_file_in_array(char* string, int vet[]) {
    FILE *file;
    char filename[100];

    int i = 0;

    snprintf(filename, sizeof(filename), string);

    file = open_file(string, "r");

    while (fscanf(file, "%d, ", &vet[i]) == 1) {
        i++;
    }

    return vet;
}

int get_array_size(int *n) {
    CLR_SCREEN;

    int i, integer_chars, length;
    char input_buffer[BUFFER_SIZE], integer_buffer[BUFFER_SIZE];
    bool loopAgain = false;

    do {
        fflush(stdin);
        integer_chars = 0;
        *n = 0;
        length = 0;
        i = 0;

        printf("Digite o tamanho do vetor a ser ordenado (MIN 1 & MAX 100000)\n");

        if (strlen(fgets(input_buffer, BUFFER_SIZE, stdin)) <= BUFFER_SIZE) {
            length = strlen(input_buffer);
        } else {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            loopAgain = true;
            fflush(stdin);
            CLR_SCREEN;
            continue;
        }

        while (isspace(input_buffer[i])) i++;

        if (length == i) {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (input_buffer[i] == '-') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        while (i < length && !isspace(input_buffer[i])) {
            if (!isdigit(input_buffer[i])) {
                printf("Entrada invalida! Tente novamente\n");
                getchar();
                CLR_SCREEN;
                loopAgain = true;
                break;
            }

            loopAgain = false;
            integer_buffer[integer_chars] = input_buffer[i];
            integer_chars++;
            i++;
        }

        if (loopAgain) continue;

        integer_buffer[integer_chars] = '\0';

        while(isspace(input_buffer[i])) i++;

        if (input_buffer[i] != '\0') {
            printf("Entrada invalida! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        }

        if (atoi(integer_buffer) > 100000 || atoi(integer_buffer) < 1) {
            printf("Entrada fora do intervalo! Tente novamente\n");
            getchar();
            CLR_SCREEN;
            loopAgain = true;
            continue;
        } else {
            *n = atoi(integer_buffer);
            loopAgain = false;
            break;
        }

    } while (loopAgain);

    CLR_SCREEN;

    return *n;
}

int shuffle_array(int vet[], int n) {
    int i, j, temp, count = 0;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        if(vet[i] <= vet[i+1]) {
            count++;
        } 
    }

    count = 0;

    for (i = n - 1; i > 0; i--) {
        j = rand() % n;
        temp = vet[i];
        vet[i] = vet[j];
        vet[j] = temp;
        count++;
    }

    return *vet;
}

int shuffle_array_fixed_factor(int vet[], int n) {
    int i, j, temp, count = 0;
    double randomizationFactor; //Grau de ordenacao
    double nextDouble = 0.5;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        if(vet[i] <= vet[i+1]) {
            count++;
        } 
    }

    count = 0;

    do {
        printf("Randomization Factor (MIN = 0 & MAX = 1");
        scanf("%lf", &randomizationFactor);
    } while (randomizationFactor < 0 || randomizationFactor > 1);

    for (i = n - 1; i > 0; i--) {
        nextDouble = (double)rand() / (double)RAND_MAX;
        if (nextDouble < randomizationFactor) {
            j = rand() % n;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            count++;
        }
    }

    return *vet;
}

int shuffle_array_random_factor(int vet[], int n) {
    int i, j, temp, count = 0;
    float randomizationFactor; //Grau de ordenacao
    double nextDouble;

    srand(time(NULL));

    for (i = 0; i < n; i++) {
        if(vet[i] <= vet[i+1]) {
            count++;
        } 
    }

    count = 0;

    for (i = n - 1; i > 0; i--) {
        randomizationFactor = (double)rand() / (double)RAND_MAX;
        nextDouble = (double)rand() / (double)RAND_MAX;
        if (nextDouble < randomizationFactor) {
            j = rand() % n;
            temp = vet[i];
            vet[i] = vet[j];
            vet[j] = temp;
            count++;
        }
    }

    return *vet;
}

// Escreve os dados de performance na tela
void print_array_data(SortFunction bufferAlgos[], int array_to_be_sorted[], int array_size, const char* sortName[]) {
    // Declara as comparações, trocas e o vetor que irá armazenar esses dados
    size_t comps, swaps, arrayCompsAndSwaps[MAX_ARGS];
    int i, number_of_elements = 0;

    for (i = 0; i < SORT_FUNCTIONS; i++) {
        if(bufferAlgos[i]) {
            number_of_elements++;
        }
    }

    printf("-------- TAMANHO %d --------\n", array_size);

    for (i = 0; i < number_of_elements; i++) { 
        //printf("%llu\n", number_of_elements);
        comps = 0; swaps = 0;
        // Escreve o nome do algoritmo na tela
        printf("--- %s ---\n", sortName[i]);
        // Escreve os dados do teste de perfomance na tela
        get_sort_data(bufferAlgos[i], array_to_be_sorted, 0, array_size-1, &comps, &swaps, arrayCompsAndSwaps);
    }


    printf("\n\n");
}

// Calcula os dados de performance das funções de ordenação
void get_sort_data(size_t* (*f)(int*, int, int, size_t*, size_t*, size_t*), 
int *array_to_be_sorted, int left, int array_size, size_t *comps, size_t *swaps, size_t* arrayCT)  {
    #ifdef _WIN32
        // Declara as variáveis que serão utilizadas pelas funções de medição de tempo de execução (QueryPerformance)
        LARGE_INTEGER frequency;
        LARGE_INTEGER start;
        LARGE_INTEGER end;
        double elapsed_time;

        // Limpa o vetor
        for (int i = 0; i < MAX_ARGS; i++) {
            arrayCT[i] = 0;
        }

        // Inicia o "cronômetro" para medir o tempo de execução da função de ordenação 
        QueryPerformanceFrequency(&frequency);
        QueryPerformanceCounter(&start);

        // Declara um vetor size_t* que recebe o vetor "arrayCT" das funções de ordenação
        // "ArrayCT" possui como indíces o número de comparações e trocas, respectivamente
        size_t *dataSort = f(array_to_be_sorted, left, array_size, comps, swaps, arrayCT);

        // Para o cronômetr
        QueryPerformanceCounter(&end);

        // Calcula o tempo de execução, em segundos
        elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

        // Escreve na tela o número de comparações, trocas e o tempo de execução da função de ordenação
        printf("Comparacoes = %12llu; Trocas = %12llu; Tempo = %12lf segundos\n", dataSort[0], dataSort[1], elapsed_time);
    #else
        // Limpa o vetor
        for (int i = 0; i < MAX_ARGS; i++) {
            arrayCT[i] = 0;
        }

        // Inicia o "cronômetro" para medir o tempo de execução da função de ordenação 
        clock_t begin = clock();
        clock_gettime(begin, CLOCK_REALTIME);

        // Declara um vetor size_t* que recebe o vetor "arrayCT" das funções de ordenação
        // "ArrayCT" possui como indíces o número de comparações e trocas, respectivamente
        size_t *dataSort = f(array_to_be_sorted, left, array_size, comps, swaps, arrayCT);

        // Para o cronômetro
        clock_t end = clock();
        // Calcula o tempo de execução, em segundos
        double elapsed_time = (double)(end - begin) / CLOCKS_PER_SEC;

        // Escreve na tela o número de comparações, trocas e o tempo de execução da função de ordenação
        printf("Comparacoes = %12zu; Trocas = %12zu; Tempo = %12lf segundos\n", dataSort[0], dataSort[1], elapsed_time);
    #endif

    /*
    * Após o vetor ter sido ordenado, embaralha novamente para que assim a próxima
    * função de ordenação receba um vetor desordenado
    */

    shuffle_array(array_to_be_sorted, array_size);
}