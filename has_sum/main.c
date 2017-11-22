#include <stdio.h>
#include <print_array.h>

#include "has_sum.h"


int main() {
    int array[] = {1, 8, 2, 3, 9, 3, 5};
    int numbers[2];

    print_array(array, 7);

    int k = 7;
    bool result = has_sum(array, 7, k);
    has_sum_numbers(array, 7, k, numbers);

    printf("%d\n", result);
    print_array(numbers, 2);

    return 0;
}
