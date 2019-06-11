#include <factorial.h>
#include <greatest_common_divisor.h>

#include "one_duplicate.h"

/**
 * This works based on an array with no duplicates the multiplication of all its
 * elements will be the factorial of the size of the array. Given that the only
 * possible values for those elements are from 1 to the size of the array.
 *
 * If there is only one duplicate, the multiplication of all its elements won't
 * be the same to the factorial so dividing it by the factorial will cancel out
 * any non duplicated element leaving the duplicate in the divident only.
 *
 * @param array
 * @param array_size
 * @return
 */
int one_duplicate(const int *array, int array_size) {
    int divisor = factorial(array_size);
    int divident = 1;

    for (int i = 0; i < array_size; i++) {
        divident *= array[i];
    }

    if (divisor == divident) return -1;

    int gcd = greatest_common_divisor(divident, divisor);

    return divident / gcd;
}
