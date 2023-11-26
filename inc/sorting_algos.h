#ifndef SORTING_ALGOS_H
#define SORTING_ALGOS_H

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