#include "first_duplicate.h"

/**
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
