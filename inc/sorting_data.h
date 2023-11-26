#ifndef SORTING_DATA_H
#define SORTING_DATA_H

#define MAX_ARRAY_SIZE         100000
#define BUFFER_SIZE            10
#define MIN_ARRAY_SIZE         1
#define MAX_ARGS               3
#define SORT_FUNCTIONS         7
#define RETRY_INPUT_SIZE       2

/* 
*  Declara o tipo "SortFunction", que trata-se de uma função do tipo size_t* e possui
*  seis argumentos como parâmetros, sendo esses o vetor a ser ordenado, a parte "esquerda" do
*  vetor, utilizado pelas funções "quick_sort" e "merge_sort", o tamanho do vetor a ser
*  ordenado, o número de comparações e o número de trocas. É utilizada para passar a função de ordenação
*  como argumento para a função "get_sort_data" e assim escrever seus dados na tela
*/ 
typedef size_t* (*SortFunction)(int*, int, int, size_t*, size_t*, size_t*);

SortFunction* get_sorting_algos(SortFunction bufferAlgos[], const char *sortName[]);

// Escolhe o tipo do vetor
int* get_type_of_array(int *array_to_be_sorted);

// Recebe o tamanho do vetor
int get_array_size(int *n);

// Escreve o arquivo que contém os valores para serem ordenados em um vetor
int* write_file_in_array(char* string, int vet[]);

// Embaralha um vetor
int shuffle_array(int vet[], int n);

// Embaralha um vetor com um grau de aleatorização fixo
int shuffle_array_fixed_factor(int vet[], int n);

// Embaralha um vetor com um grau de aleatorização aleatório
int shuffle_array_random_factor(int vet[], int n);

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
int *array_to_be_sorted, int left, int array_size, size_t *comps, size_t *swaps, size_t* arrayCT);

#endif