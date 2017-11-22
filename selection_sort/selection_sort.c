#include "selection_sort.h"

/**
 * Consider sorting n numbers stored in array @param a by first finding the smallest element
 * of @param a and exchanging it with the element in @param a[0]. Then find the second smallest
 * element of @param a, and exchange it with @param a[1]. Continue in this manner for the first @param a_size - 1
 * elements of @param a
 *
 * Array a to a + i is always sorted in any i loop iteration
 *
 * It only needs to run for the first a_size - 1 iteration cause the smallest value of a remaining array of 1 element
 * is that element
 *
 * Best-case theta of n-squared
 * Worst-case theta of n-squared
 *
 * @param a
 * @param a_size
 */
void selection_sort(int *a, int a_size) {
    for (int i = 0; i < a_size - 1; i++) {
        int *key = a + i;

        for (int j = i + 1; j < a_size; j++) {
            if (a[j] < *key) {
                key = a + j;
            }
        }

        if (key != a + i) {
            int smallest_element = *key;
            *key = a[i];
            a[i] = smallest_element;
        }
    }
}
