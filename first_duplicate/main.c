#include <stdio.h>

#include "first_duplicate.h"

int main() {
    static const int ARRAY_SIZE = 6;
    static const int array[] = {2, 1, 3, 5, 3, 2};

    int r = first_duplicate2(array, ARRAY_SIZE);

    printf("%d", r);

    return 0;
}
