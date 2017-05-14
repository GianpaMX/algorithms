#include <stdio.h>
#include "selection_sort.h"

static const int SIZE = 6;

void print_array(const int *array, int size);

int main() {
    int array[] = {5, 2, 4, 6, 1, 3};

    print_array(array, SIZE);

    selection_sort(array, SIZE);

    print_array(array, SIZE);

    return 0;
}

void print_array(const int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", array[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}
