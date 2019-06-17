#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "closest_pairs.h"


int main() {
    int a_array[] = {8, 15, 9};
    int b_array[] = {8, 11, 12};
    int k = 20;

    int a_size = sizeof(a_array) / sizeof(int);
    int b_size = sizeof(b_array) / sizeof(int);

    Pair *pairs = malloc(a_size * b_size * sizeof(Pair));
    int pairs_size = closest_pairs(a_array, a_size, b_array, b_size, k, pairs);

    for (int i = 0; i < pairs_size; i++) {
        printf("%d, %d\n", pairs[i].first, pairs[i].second);
    }

    return 0;
}
