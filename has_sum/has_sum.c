#include <malloc.h>
#include <stdbool.h>
#include <linear_search.h>

#include "has_sum.h"

int index_of(int value, int *array, int size);

/**
 * The sum of two numbers equals K is:
 * a + b = K
 * We can rewrite the equation like:
 * b = K - a
 * That means that if we already know the difference we know the value of b
 *
 * So we will iterate the array saving the possible b that we need to find and then
 * when we iterate we check if the current item is that b that we are looking for
 *
 * Time and Space complexity O(n)
 *
 * @param input
 * @param input_size
 * @param k
 * @return
 */
bool has_sum(const int *input, int input_size, int k) {
    int *differences = malloc(input_size * sizeof(int));
    bool result = false;

    for (int i = 0; i < input_size; i++) {
        if (index_of(input[i], differences, i) >= 0) {
            result = true;
            break;
        }

        differences[i] = k - input[i];
    }

    free(differences);
    return result;
}

/**
 * To return the numbers we just find the number at the same position in the input array since the
 * differences array is one-to-one with the input array
 *
 * @param input
 * @param input_size
 * @param k
 * @param result
 */
void has_sum_numbers(const int *input, int input_size, int k, int *result) {
    int *differences = malloc(input_size * sizeof(int));

    for (int i = 0; i < input_size; i++) {
        int index = index_of(input[i], differences, i);
        if (index >= 0) {
            result[0] = input[index];
            result[1] = input[i];
            break;
        }

        differences[i] = k - input[i];
    }

    free(differences);
}

int index_of(int value, int *array, int size) {
    return linear_search(value, array, size);
}
