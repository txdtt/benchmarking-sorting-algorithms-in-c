# Benchmarking sorting algorithms in C
[![License: GPL 3.0](https://img.shields.io/badge/License-GPL%203.0-green.svg)](https://www.gnu.org/licenses/gpl-3.0)
<p align="justify">Este programa realiza um teste de perfomance para 7 tipos diferentes de algoritmos de ordenação, sendo eles: bubble sort, insertion sort, selection sort, shell sort, bead sort, quick sort e merge sort. A performance é avaliada a partir de três critérios: número de comparações realizadas, quantidade de trocas realizadas e tempo de execução. O programa aceita vetores de tamanho 1 até 100000.</p>

## Como Compilar
<p align="justify">Rode "make" na raíz do diretório.</p>

```
make
```

## Como adicionar novas funções
<p align="justify">A função de ordenação a ser inserida deve aderir aos seguintes critérios: ser do tipo long long int* e receber como parâmetros um vetor inteiro, dois valores inteiros e três ponteiros do tipo long long int*. Esses ponteiros são necessários para o cálculo das comparações  e trocas, sendo o terceiro um ponteiro para um vetor, que armazenará esses dois valores e irá retorná-los na função.</p>

```
make
```

## License
<p align="justify">This project is licensed under the GNU General Public License v3.0 - see the LICENSE file for details.</p>
