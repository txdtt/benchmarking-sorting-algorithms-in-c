# Benchmarking sorting algorithms in C
[![License: GPL 3.0](https://img.shields.io/badge/License-GPL%203.0-green.svg)](https://www.gnu.org/licenses/gpl-3.0)
<p align="justify">Este programa realiza um teste de perfomance para 7 tipos diferentes de algoritmos de ordenação, sendo eles: Quick Sort, Merge Sort, Shell Sort, Insertion Sort, Selection Sort, Bubble Sort e Bead Sort. A performance é avaliada a partir de três critérios: número de comparações realizadas, quantidade de trocas realizadas e tempo de execução, medido em segundos. O programa aceita vetores de tamanho 1 até 100000.</p>

## Como compilar
<p align="justify">Rode "make" na raíz do diretório.</p>

```
make
```

## Como adicionar novas funções
<p align="justify">A função de ordenação a ser inserida deve aderir aos seguintes critérios: ser do tipo size_t* e receber como parâmetros um vetor inteiro, dois valores inteiros e três ponteiros do tipo size_t*. Esses ponteiros são necessários para o cálculo das comparações  e trocas, sendo o terceiro um ponteiro para um vetor, que armazenará esses dois valores e irá retorná-los na função.</p>

```c
size_t* sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT);
```

## License
<p align="justify">This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.</p>
