#include <stdlib.h>
#include <memory.h>

#include "closest_pairs.h"

int intcmp(const void *a, const void *b);

int paircmp(const void *a, const void *b);

/**
 * If we sort both arrays we will be able to compare the sum of the greatest
 * element of a with the smallest element of b.
 *
 * if the sum is smaller than k we add that pair to the result and then increase
 * the pointer of b so the next sum will be greater.
 *
 * if the sum is greater than k we decrease the pointer of a so the next sum
 * will be smaller.
 *
 *    |  7 |  8 | 14
 * ---+----+----+----
 *  5 |    |    | 19
 * --+----+----+----
 * 10 |    | 18 |  x
 * ---+----+----+----
 * 14 |  x |  x |
 *
 * @param a_array
 * @param a_size
 * @param b_array
 * @param b_size
 * @param k
 * @param pairs
 * @return
 */
int closest_pairs(const int *a_array,
                  int a_size,
                  const int *b_array,
                  int b_size,
                  int k,
                  Pair *pairs) {

    int *sorted_a = malloc(a_size * sizeof(int));
    memcpy(sorted_a, a_array, a_size * sizeof(int));
    qsort(sorted_a, a_size, sizeof(int), intcmp);

    int *sorted_b = malloc(b_size * sizeof(int));
    memcpy(sorted_b, b_array, b_size * sizeof(int));
    qsort(sorted_b, b_size, sizeof(int), intcmp);

    int a = a_size - 1, b = 0;
    int p = 0;
    while (a >= 0 && b < b_size) {
        int sum = sorted_a[a] + sorted_b[b];
        if (sum <= k) {
            pairs[p].first = sorted_a[a];
            pairs[p].second = sorted_b[b];
            p++;
            b++;
        } else {
            a--;
        }
    }
    qsort(pairs, p, sizeof(Pair), paircmp);

    for (int i = 1; i < p; i++) {
        if (pairs[i].first + pairs[i].second != k) {
            p--;
        }
    }

    return p;
}

int intcmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

int paircmp(const void *a, const void *b) {
    Pair *pair_a = (Pair *) a;
    Pair *pair_b = (Pair *) b;

    return pair_b->first + pair_b->second - pair_a->first - pair_a->second;
}
