#include <print_array.h>
#include "minimun_swaps_2.h"

int abs_int(int n);

void swap_array_elements(int *i, int *j);

/**
 * Starts finding the farthest element from its position, then swap it for the
 * element that will be in its position or the closest one.
 *
 * TODO: Improve for 50,000 array elements
 *
 * @param a
 * @param a_size
 * @return
 */
int minimun_swaps_2(int *a, int a_size) {
    print_array(a, a_size);

    int max_diff = 0;
    int max_index = -1;
    for (int i = 0; i < a_size; i++) {
        int diff = abs_int(a[i] - 1 - i);
        if (diff > max_diff) {
            max_diff = diff;
            max_index = i;
        }
    }

    if (max_diff == 0) return 0;

    int min_diff = 0;
    int min_index = -1;
    for (int i = 0; i < a_size; i++) {
        if (i == max_index) continue;
        int new_diff = a[i] - 1 - max_index;
        if (new_diff == 0) {
            swap_array_elements(a + max_index, a + i);
            return 1 + minimun_swaps_2(a, a_size);
        }
        new_diff = abs_int(new_diff);
        if (new_diff < min_diff) {
            min_diff = new_diff;
            min_index = i;
        }
    }

    swap_array_elements(a + max_index, a + min_index);

    return 1 + minimun_swaps_2(a, a_size);
}

void swap_array_elements(int *i, int *j) {
    int tmp = *i;
    *i = *j;
    *j = tmp;
}

int abs_int(int n) {
    return n < 0 ? (-1 * n) / n : n;
}
