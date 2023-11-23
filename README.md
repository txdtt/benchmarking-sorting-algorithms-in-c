# Benchmarking sorting algorithms in C
<p align="justify">Este programa realiza um teste de perfomance para 7 tipos diferentes de algoritmos de ordenação, sendo eles: bubble sort, insertion sort, selection sort, shell sort, 
bead sort, quick sort e merge sort. A performance é avaliada a partir de três critérios:
número de comparações realizadas, quantidade de trocas realizadas e tempo de execução.
O programa aceita vetores de tamanho 1 até 100000.</p>

## Como adicionar novas funções
<p align="justify">A função de ordenação a ser inserida deve aderir aos seguintes critérios: ser do tipo
long long int* e receber como parâmetros um vetor inteiro, dois valores inteiros e três
ponteiros do tipo long long int*. Esses ponteiros são necessários para o cálculo das comparações 
e trocas, sendo o terceiro um ponteiro para um vetor, que armazenará esses dois valores e irá
retorná-los na função.</p>
