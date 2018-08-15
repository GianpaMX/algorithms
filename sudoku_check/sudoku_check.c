#include <stdlib.h>
#include <btree.h>

#include "sudoku_check.h"


int char_hash(const void *c);

int get_square(int j);

bool sudoku_check(arr_arr_char grid) {
    btree *square_btree[3];

    for (int i = 0; i < 9; i++) {
        btree *row = btree_init(&char_hash);
        btree *column = btree_init(&char_hash);

        if (i == 0 || i == 3 || i == 6) {
            square_btree[0] = btree_init(&char_hash);
            square_btree[1] = btree_init(&char_hash);
            square_btree[2] = btree_init(&char_hash);
        }

        for (int j = 0; j < 9; j++) {
            if (grid.arr[i].arr[j] != '.') {
                if (btree_contains(row, grid.arr[i].arr + j)) {
                    return false;
                }
                btree_put(row, grid.arr[i].arr + j);

                if (btree_contains(square_btree[get_square(j)], grid.arr[i].arr + j)) {
                    return false;
                }
                btree_put(square_btree[get_square(j)], grid.arr[i].arr + j);
            }

            if (grid.arr[j].arr[i] != '.') {
                if (btree_contains(column, grid.arr[j].arr + i)) {
                    return false;
                }
                btree_put(column, grid.arr[j].arr + i);
            }
        }

        if (i == 2 || i == 5 || i == 8) {
            btree_free(square_btree[0]);
            btree_free(square_btree[1]);
            btree_free(square_btree[2]);
        }

        btree_free(row);
        btree_free(column);
    }
    return true;
}

int get_square(int j) {
    return j < 3 ? 0 : j < 6 ? 1 : 2;
}


arr_arr_char *sudoku_new_grid() {
    arr_arr_char *grid = malloc(sizeof(arr_arr_char));

    grid->size = 9;
    grid->arr = malloc(9 * sizeof(arr_char));

    for (int i = 0; i < 9; i++) {
        grid->arr->size = 9;
        grid->arr[i].arr = malloc(9 * sizeof(char));
        for (int j = 0; j < 9; j++) {
            grid->arr[i].arr[j] = '.';
        }
    }

    return grid;
}

void sudoku_free_grid(arr_arr_char *grid) {
    for (int i = 0; i < 9; i++) {
        grid->arr->size = 9;
        free(grid->arr[i].arr);
    }
    free(grid->arr);
    free(grid);
}

int char_hash(const void *c) {
    return *(char *) c;
}
