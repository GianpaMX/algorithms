#include <stdio.h>
#include "print_array.h"

void print_array(const int *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%2d", array[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}

void print_char_array(const char *array, int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%c", array[i]);
        if (i + 1 < size) {
            printf(", ");
        }
    }
    printf("]\n");
}

