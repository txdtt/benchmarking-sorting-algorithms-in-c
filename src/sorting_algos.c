#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

#include "../inc/sorting_algos.h"

#ifdef _WIN32
    #include <windows.h>
    #include <psapi.h>
#endif

#define BEAD(i, j) beads[i * max + j]

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

size_t* bubble_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int i, j, swap_occured = 1;

    n++;
    
    for(i = 0; i < n-1 && swap_occured; i++){
        swap_occured = 0;
        for(j = 0; j < n-i-1; j++){
          (*comps) += 1;
          if (array_to_be_sorted[j] > array_to_be_sorted[j+1]){
              (*swaps) += 1;
              swap(&array_to_be_sorted[j], &array_to_be_sorted[j+1]);
              swap_occured = 1;
          }
        }
    }

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* insertion_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int i, j, aux;

    n++;

    for(i = 1; i < n; i++){
        aux = array_to_be_sorted[i]; 
        for(j = i-1; j >= 0 && aux < array_to_be_sorted[j]; j--) {
            (*comps)++; 
            (*swaps)++;
            array_to_be_sorted[j+1] = array_to_be_sorted[j];
        }
        if (j >= 0)
            (*comps)++;
        array_to_be_sorted[j+1] = aux;
    }

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* selection_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int i, j, min_ind;

    n++;

    for(i = 0; i < n-1; i++){
        min_ind = i;
        for(j = i+1; j < n; j++) {
            (*comps)++;
            if (array_to_be_sorted[j] < array_to_be_sorted[min_ind])
                min_ind = j;
        }
        if (min_ind != i) {
            (*swaps)++;
            swap(&array_to_be_sorted[min_ind], &array_to_be_sorted[i]);
        }
    }

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* shell_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int i, j, k, aux;

    n++;

    for(k = n/2; k > 0; k /= 2)
    {
        for(i = k; i < n; i++){
            aux = array_to_be_sorted[i]; 
            for(j = i - k; j >= 0 && aux < array_to_be_sorted[j]; j -= k) {
                (*comps)++;
                (*swaps)++;
                array_to_be_sorted[j+k] = array_to_be_sorted[j];
            }
            if (j >= 0)
                (*comps)++;
            array_to_be_sorted[j+k] = aux;
        }
    }

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* quick_sort(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT) {
	if (left < right) {
        int med = (left+right)/2;
        if (array_to_be_sorted[left] <= array_to_be_sorted[med] && array_to_be_sorted[left] >= array_to_be_sorted[right]){
            (*comps) += 2;
        }
        else if (array_to_be_sorted[left] >= array_to_be_sorted[med] && array_to_be_sorted[left] <= array_to_be_sorted[right]){
            (*comps) += 4;
        }
        else if (array_to_be_sorted[med] <= array_to_be_sorted[left] && array_to_be_sorted[med] >= array_to_be_sorted[right]){
            (*comps) += 6;
            (*swaps)++;
            swap(&array_to_be_sorted[left], &array_to_be_sorted[med]);
        }
        else if (array_to_be_sorted[med] >= array_to_be_sorted[left] && array_to_be_sorted[med] <= array_to_be_sorted[right]){
            (*comps) += 6;
            (*swaps)++;
            swap(&array_to_be_sorted[left], &array_to_be_sorted[med]);
        } 
        else {
            (*comps) += 8;
            (*swaps)++;
            swap(&array_to_be_sorted[left], &array_to_be_sorted[right]);
        }

        int index_pivot = partition(array_to_be_sorted, left, right, comps, swaps, arrayCT)[2];
        quick_sort(array_to_be_sorted, left, index_pivot - 1, comps, swaps, arrayCT);
        quick_sort(array_to_be_sorted, index_pivot + 1, right, comps, swaps, arrayCT);	
	}

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* partition(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int pivot = array_to_be_sorted[left];
    int i = left;
    int j;

    for (j = left + 1; j <= right; j++) {
        (*comps)++;
        if (array_to_be_sorted[j] <= pivot) {
            (*swaps)++;
            i+=1;
            swap(&array_to_be_sorted[i], &array_to_be_sorted[j]);
        }
    }
    (*swaps)++;
    swap(&array_to_be_sorted[left], &array_to_be_sorted[i]);

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;
    arrayCT[2] = i;
    
    return arrayCT; 
}

size_t* merge_sort(int array_to_be_sorted[], int left, int right, size_t *comps, size_t *swaps, size_t *arrayCT) {   
    int mid;

    if (left < right) {
        mid = floor((left + right) / 2);
        merge_sort(array_to_be_sorted, left, mid, comps, swaps, arrayCT);
        merge_sort(array_to_be_sorted, mid + 1, right, comps, swaps, arrayCT);
        merge(array_to_be_sorted, left, mid, right, comps, swaps, arrayCT);
    }

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}

size_t* merge(int array_to_be_sorted[], int left, int mid, int right, size_t *comps, size_t *swaps, size_t *arrayCT) {
    int *temp, p1, p2, size, i, j, k, fim1 = 0, fim2 = 0;
    size = right - left + 1;
    p1 = left;
    p2 = mid + 1;

    temp = (int*) malloc (size * sizeof(int));
    
    if (temp != NULL) {
        for (i = 0; i < size; i++) {

            if (!fim1 && !fim2) {
                (*comps)++;
                if (array_to_be_sorted[p1] < array_to_be_sorted[p2]) {
                    (*swaps)++;
                    temp[i] = array_to_be_sorted[p1++];
                }
                else {
                    (*swaps)++;
                    temp[i] = array_to_be_sorted[p2++];
                }

                if (p1 > mid) {
                    (*swaps)++;
                    fim1 = 1;
                }

                if (p2 > right) {
                    (*swaps)++;
                    fim2 = 1;
                }

            } else {
                (*comps)++;
                if (!fim1) {
                    (*swaps)++;
                    temp[i] = array_to_be_sorted[p1++];
                } else {
                    (*swaps)++;
                    temp[i] = array_to_be_sorted[p2++];
                }
            }
        }

        for (j = 0, k = left; j < size; j++, k++) {
            array_to_be_sorted[k] = temp[j];
        }
    }

    free(temp);

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;

}

size_t* bead_sort(int array_to_be_sorted[], int m, int n, size_t *comps, size_t *swaps, size_t *arrayCT) {
    size_t sum, max;
    int i, j;
    unsigned char *beads;

    n++;

    // Encontra o elemento máximo no array 
    for (i = 1, max = array_to_be_sorted[0]; i < n; i++) {
        (*comps)++;
        if (array_to_be_sorted[i] > max) {
            max = array_to_be_sorted[i];
        }
    }

    // Aloca memória para o array de contas
    beads = malloc(max * n);

    // Marca as contas
    for (i = 0; i < n; i++) {
        (*swaps)++;
        for (j = 0; j < array_to_be_sorted[i]; j++) {
            BEAD(i, j) = 1;
        }
    }

    // Conta o número de contas em cada poste
    for (j = 0; j < max; j++) {
        for (sum = i = 0; i < n; i++) {
            sum += BEAD(i, j);
            BEAD(i, j) = 0;
        }
        // Marca as contas na parte inferior
        for (i = n - sum; i < n; i++) {
            BEAD(i, j) = 1;
        }
    }

    // Atribui os valores ordenados de volta ao array
    for (i = 0; i < n; i++) {
        for (j = 0; j < max && BEAD(i, j); j++);
        array_to_be_sorted[i] = j;
    }

    // Libera a memória alocada
    free(beads);

    arrayCT[0] = *comps;
    arrayCT[1] = *swaps;

    return arrayCT;
}