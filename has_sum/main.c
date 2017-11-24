#include <stdio.h>
#include <print_array.h>

#include "has_sum.h"


int main() {
    static const int K = 7;

    static const int ARRAY_SIZE = 7;
    static const int array[] = {1, 8, 2, 3, 9, 3, 5};

    int numbers[2];

    printf("K = %d\n", K);
    print_array(array, ARRAY_SIZE);

    if (has_sum(array, ARRAY_SIZE, K)) {
        has_sum_numbers(array, ARRAY_SIZE, K, numbers);
        print_array(numbers, 2);
    } else {
        printf("No numbers");
    }

    return 0;
}
