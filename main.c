#include <stdio.h>
#include "print_array.h"
#include "non_zero.h"


int main() {
    int array[] = {1, 0, 2, 0, 0, 3, 0};

    print_array(array, 7);

    int non_zeros = non_zero(array, 7);

    printf("%d\n", non_zeros);
    print_array(array, 7);

    return 0;
}
