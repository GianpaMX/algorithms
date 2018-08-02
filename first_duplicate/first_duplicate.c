#include <btree.h>
#include "first_duplicate.h"

/**
 * A duplicate should be in the right side of any number.
 *
 * We have two pointers, i is the index iterating the array, j is the pointer looking for duplicates.
 *
 * A duplicate of index i can only be in the right side of the array after i and before the last index we found,
 * last index is the end of the array or the smallest index found so far.
 *
 * This solution is in constance space but O(n^2)
 *
 * @param a
 * @param size
 * @return
 */
int first_duplicate(int *a, int size) {
    int i = 0;
    int j = 1;

    int last_index = size;
    while (i < last_index && j < last_index) {
        if (a[i] == a[j]) {
            last_index = j;
        }

        if (++j >= last_index) {
            j = ++i + 1;
        }
    }
    return last_index != size ? a[last_index] : -1;
}

int int_hash(const void *i);

/**
 * In a better implementation of btree this is should be faster than first_duplicate since it's
 * in O(n) but n space.
 *
 * This saves numbers found when iterating the array and when the first duplicate is found; it should be the
 * one with the smallest index
 *
 * @param a
 * @param size
 * @return
 */
int first_duplicate2(int *a, int size) {
    int result = -1;
    btree *numbers = btree_init(int_hash);

    for (int i = 0; i < size; i++) {
        if (numbers->contains(numbers, a + i)) {
            result = a[i];
            break;
        }

        numbers->put(numbers, a + i);
    }

    btree_free(numbers);
    return result;
}

int int_hash(const void *i) {
    return *(int *) i;
}

