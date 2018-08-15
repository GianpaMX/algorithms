#include <stdlib.h>
#include <stdio.h>
#include <print_array.h>

#include "sudoku_check.h"


int main() {

    arr_arr_char *grid = sudoku_new_grid();

    grid->arr[0].arr[3] = '1';
    grid->arr[0].arr[4] = '4';
    grid->arr[0].arr[7] = '2';

    grid->arr[1].arr[2] = '6';

    grid->arr[3].arr[2] = '1';

    grid->arr[4].arr[1] = '6';
    grid->arr[4].arr[2] = '7';
    grid->arr[4].arr[8] = '9';

    grid->arr[5].arr[6] = '1';
    grid->arr[5].arr[7] = '8';

    grid->arr[6].arr[2] = '3';
    grid->arr[6].arr[8] = '6';

    grid->arr[7].arr[5] = '5';
    grid->arr[8].arr[3] = '7';

    for (int i = 0; i < 9; i++) {
        print_char_array(grid->arr[i].arr, 9);
    }

    printf("result = %d", sudoku_check(*grid));

    sudoku_free_grid(grid);

    return 0;
}
