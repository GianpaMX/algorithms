#ifndef ALGORITHMS_SUDOKU_CHECK_H
#define ALGORITHMS_SUDOKU_CHECK_H

#include <stdbool.h>

typedef struct {
    int size;
    char *arr;
} arr_char;

typedef struct {
    int size;
    arr_char *arr;
} arr_arr_char;

arr_arr_char *sudoku_new_grid();

void sudoku_free_grid(arr_arr_char *grid);

bool sudoku_check(arr_arr_char grid);

#endif //ALGORITHMS_SUDOKU_CHECK_H
