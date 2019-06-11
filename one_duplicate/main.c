#include <stdio.h>

#include "one_duplicate.h"

int main() {
    static const int ARRAY_SIZE = 5;
    static const int array[] = {2, 1, 3, 4, 3};

    int r = one_duplicate(array, ARRAY_SIZE);

    printf("%d", r);

    return 0;
}
