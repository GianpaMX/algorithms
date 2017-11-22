#include <malloc.h>
#include <stdbool.h>
#include "has_sum.h"

int index_of(int *array, int size, int value);

/**
 * You have an array with N elements and you should find two elements with given sum K
 *
 * @param input
 * @param input_size
 * @param k
 * @return
 */
bool has_sum(int *input, int input_size, int k) {
    int *differences = malloc(input_size * sizeof(int));
    int differences_size = 0;

    for (int i = 0; i < input_size; i++) {
        if (index_of(differences, differences_size, input[i]) >= 0) {
            free(differences);
            return true;
        }

        differences[differences_size++] = k - input[i];
    }

    free(differences);
    return false;
}

void has_sum_numbers(int *input, int input_size, int k, int *result) {
    int *numbers = malloc(input_size * sizeof(int));
    int *differences = malloc(input_size * sizeof(int));
    int differences_size = 0;
    int index;

    for (int i = 0; i < input_size; i++) {
        index = index_of(differences, differences_size, input[i]);
        if (index >= 0) {
            result[0] = numbers[index];
            result[1] = input[i];
            break;
        }

        numbers[differences_size] = input[i];
        differences[differences_size] = k - input[i];
        differences_size++;
    }

    free(numbers);
    free(differences);
}

int index_of(int *array, int size, int value) {
    for (int i = 0; i < size; i++) {
        if (array[i] == value) return i;
    }
    return -1;
}

