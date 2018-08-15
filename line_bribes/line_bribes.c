#include <stdlib.h>

#include "line_bribes.h"

int *new_line(int size);

int calculate_diff(const int *line, int size, const int *original, int i);

void slice_line(int *line, int end_position, int places);

int line_bribes(const int *queue, int size) {
    int bribes = 0;
    int *original = new_line(size);

    for (int i = 0; i < size; i++) {
        if (queue[i] != original[i]) {
            int diff = calculate_diff(queue, size, original, i);
            if (diff > MAX_BRIBES) return TOO_CHAOTIC;

            slice_line(original, i, diff);

            bribes += diff;
        }
    }

    free(original);

    return bribes;
}

void slice_line(int *line, int end_position, int places) {
    int tmp = line[end_position + places];
    for (int i = 0; i < places; i++) {
        line[end_position + places - i] = line[end_position + places - i - 1];
    }
    line[end_position] = tmp;
}

int calculate_diff(const int *line, int size, const int *original, int i) {
    int j = i + 1;
    while (j < size && original[j] != line[i]) j++;
    return j - i;
}

int *new_line(int size) {
    int *original = malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        original[i] = i + 1;
    }
    return original;
}
