#include <stdio.h>

#include "../inc/sorting_data.h"
#include "../inc/file_io.h"
#include "../inc/sorting_algos.h"
#include "../inc/utils.h"

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

/* 
* Visualizador de performance para algoritmos de ordenação  
* Este programa realiza um teste de perfomance para 7 tipos diferentes de algoritmos
* de ordenação, sendo eles: bubble sort, insertion sort, selection sort, shell sort, 
* bead sort, quick sort e merge sort. A performance é avaliada a partir de três critérios:
* número de comparações realizadas, quantidade de trocas realizadas e tempo de execução.
* O programa aceita vetores de tamanho 1 até 100000.
*/                                     

int main(int argc, char *argv[]) {
    CLR_SCREEN;

    int array_to_be_sorted[MAX_ARRAY_SIZE], array_size, retry;

    // Vetor do tipo "SortFunction". Este vetor possui os ponteiros para as funções de ordenação
    // SortFunction bufferAlgos[] = {quick_sort, merge_sort, shell_sort, insertion_sort, selection_sort, bubble_sort, bead_sort};
    SortFunction bufferAlgos[SORT_FUNCTIONS];

    // Vetor com os nomes das funções
    // const char *sortName[] = {"QUICK SORT", "MERGE SORT", "SHELL SORT", "INSERTION SORT", "SELECTION SORT", "BUBBLE SORT", "BEAD SORT"}; 
    const char *sortName[SORT_FUNCTIONS]; 

    welcome_msg();

    do {
        CLR_SCREEN

        get_sorting_algos(bufferAlgos, sortName);

        get_type_of_array(array_to_be_sorted);

        get_array_size(&array_size);

        print_array_data(bufferAlgos, array_to_be_sorted, array_size, sortName);

        restart(&retry);

    } while (retry == '1');

    exit_program();

    return 0;
}