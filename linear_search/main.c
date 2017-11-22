#include <stdio.h>
#include <print_array.h>

#include "linear_search.h"


static const int SIZE = 6;

int main() {
    int array[] = {5, 2, 4, 6, 1, 3};

    print_array(array, SIZE);

    int index = linear_search(6, array, SIZE);

    if (index == -1) {
        printf("Not found");
        return -1;
    }

    printf("At index %d", index);

    return 0;
}
