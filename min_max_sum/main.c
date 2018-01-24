#include <stdio.h>
#include <stdlib.h>

#include "min_max_sum.h"

int main() {
    int *arr = malloc(sizeof(int) * 5);
    for (int arr_i = 0; arr_i < 5; arr_i++) {
        scanf("%i", &arr[arr_i]);
    }
    min_max_sum(5, arr);
    return 0;
}
