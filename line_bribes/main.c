#include <stdio.h>
#include "line_bribes.h"

static const int SIZE = 8;

int main() {
    int line[] = {1, 2, 5, 3, 7, 8, 6, 4};

    int bribes = line_bribes(line, SIZE);

    if (bribes == TOO_CHAOTIC) {
        printf("Too chaotic");
    } else {
        printf("bribes = %d", bribes);
    }

    return 0;
}
