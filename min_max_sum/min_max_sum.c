#include <stdio.h>
#include "min_max_sum.h"

void min_max_sum(int arr_size, int *arr) {
    long long int sum = 0;
    int min = 1000000001, max = 0;
    for (int i = 0; i < arr_size; i++) {
        sum += arr[i];
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("%lld %lld", sum - max, sum - min);
}
