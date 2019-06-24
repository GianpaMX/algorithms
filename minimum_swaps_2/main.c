#include <stdio.h>
#include "minimun_swaps_2.h"

int main() {
    int arr[] = {7, 1, 3, 2, 4, 5, 6};

    int swaps = minimun_swaps_2(arr, sizeof(arr) / sizeof(int));

    printf("%d\n", swaps);

    return 0;
}
