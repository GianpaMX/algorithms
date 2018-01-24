#include <stdlib.h>
#include "diagonal_difference.h"

int diagonal_difference(int n, int **a) {
    int dif = 0;
    for (int i = 0, j = n - 1; i < n && j >= 0; i++, j--) {
        dif += a[i][i] - a[i][j];
    }
    return abs(dif);
}
