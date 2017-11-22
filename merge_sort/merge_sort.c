#include <malloc.h>

#include "merge_sort.h"

/**
 * Comparing smallest element of each array to decide which one should go first, after any of them have been iterated
 * continue appending the rest of the other
 * @param a Output array
 * @param left sorted array
 * @param left_size
 * @param right sorted array
 * @param right_size
 */
void merge(int *a, int *left, int left_size, int *right, int right_size) {
    int i, j, k;

    i = j = k = 0;

    while (i < left_size && j < right_size) {
        a[k++] = left[i] < right[j] ? left[i++] : right[j++];
    }

    // only 1 of these loops will iterate
    while (i < left_size) a[k++] = left[i++];
    while (j < right_size) a[k++] = right[j++];
}

/**
 * Divide the a array recursively in two until have a set of arrays of 1-element, then merge these smaller arrays
 * element by element comparing which one should go first
 *
 * @param a
 * @param a_size
 */
void merge_sort(int *a, int a_size) {
    int *left, *right;

    if (a_size == 1) return;

    int left_size = a_size / 2;
    int right_size = a_size - left_size;

    left = (int *) malloc(left_size * sizeof(int));
    for (int i = 0; i < left_size; i++) {
        left[i] = a[i];
    }

    right = (int *) malloc(right_size * sizeof(int));
    for (int i = 0; i < right_size; i++) {
        right[i] = a[left_size + i];
    }

    merge_sort(left, left_size);
    merge_sort(right, right_size);

    merge(a, left, left_size, right, right_size);

    free(left);
    free(right);
}
