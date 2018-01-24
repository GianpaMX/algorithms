#include <stdio.h>
#include <stdlib.h>
#include "diagonal_difference.h"

int main() {
    int n;
    scanf("%i", &n);

    int **a = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            scanf("%i", &a[i][j]);
        }
    }

    int result = diagonal_difference(n, a);
    printf("%d\n", result);

    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);

    return 0;
}
