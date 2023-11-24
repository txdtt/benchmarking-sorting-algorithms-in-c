#ifndef SORTING_H
#define SORTING_H

/* 
*  Declara o tipo "SortFunction", que trata-se de uma função do tipo size_t* e possui
*  seis argumentos como parâmetros, sendo esses o vetor a ser ordenado, a parte "esquerda" do
*  vetor, utilizado pelas funções "quick_sort" e "merge_sort", o tamanho do vetor a ser
*  ordenado, o número de comparações e o número de trocas. É utilizada para passar a função de ordenação
*  como argumento para a função "get_sort_data" e assim escrever seus dados na tela
*/ 
typedef size_t* (*SortFunction)(int*, int, int, size_t*, size_t*, size_t*);

/* 
*  Função que escreve os dados de perfomance do algoritmo de ordenação na tela.
*  Recebe como parâmentro o vetor do tipo "SortFunction", o vetor a ser ordenado,
*  o tamanho do vetor e o nome do vetor.
*/
void print_array_data(SortFunction bufferAlgos[], int array_to_be_sorted[], int array_size, const char* sortName[]);

/* 
*  Função que escreve na tela os dados de performance do algoritmo de ordenação.
*  Recebe como parâmetro a função de ordenação, o vetor a ser ordenado, a parte "esquerda" do
*  vetor, utilizado pelas funções "quick_sort" e "merge_sort", o tamanho do vetor a ser
*  ordenado, o número de comparações, o número de trocas e o vetor que terá como índices
*  as comparações e trocas. É necessário utilizar um vetor para armazenar as comparações
*  e trocas pois o ponteiro "size_t* dataSort" recebe a função de ordenação que foi passada como parâmetro,
*  e as funções de ordenação retornam um ponteiro para o vetor "arrayCT", que tem como índices
*  as comparações e trocas realizadas pela função de ordenação.
*/
void get_sort_data(size_t* (*f)(int*, int, int, size_t*, size_t*, size_t*), 
int *array_to_be_sorted, int left, int array_size, size_t *comps, size_t *swaps, size_t* arrayCT) ;

void swap(int *x, int *y);

size_t* bubble_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* insertion_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* selection_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* shell_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* quick_sort(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* partition(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* merge_sort(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* merge(int array_to_be_sorted[], int left, int mid, int right, size_t *comps, size_t *swaps, size_t *arrayCT);

size_t* bead_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);

#endif