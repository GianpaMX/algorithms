#include <stdio.h>
#include "maximun_subarray.h"

static const int SIZE = 16;

int main() {
    int array[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    subarray result = maximun_subarray(array, 0, SIZE - 1);

    printf("{low = %d, high = %d, sum = %d}", result.low, result.high, result.sum);
    return 0;
}
