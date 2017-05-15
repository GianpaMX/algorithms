#include <limits.h>
#include "maximun_subarray.h"

/**
 * Sum to the left saving the maximun sum and marking the index, then sum to the right saving the sum and marking the
 * maximun index then sum the left + righ sums
 * @param array
 * @param low
 * @param mid
 * @param high
 * @return
 */
subarray maximun_crossing_subarray(const int *array, int low, int mid, int high) {
    subarray result;

    int left_sum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >= low; i--) {
        sum = sum + array[i];
        if (sum > left_sum) {
            left_sum = sum;
            result.low = i;
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum = sum + array[i];
        if (sum > right_sum) {
            right_sum = sum;
            result.high = i;
        }
    }

    result.sum = left_sum + right_sum;

    return result;
}
/**
 * if we split the array in two the maximun sum should be on the left side, on the right side or accross the division
 * point. If we continue to splitting until have one-element array, that array is the maximun sum, then we pop back
 * into the two-elements array and the maximun sum could be the left element, the right element or the sum of the two.
 * @param array
 * @param low
 * @param high
 * @return
 */
subarray maximun_subarray(const int *array, int low, int high) {
    subarray result;

    if (high == low) {
        result.low = low;
        result.high = high;
        result.sum = array[low];
        return result;
    }

    int mid = (low + high) / 2;
    subarray left = maximun_subarray(array, low, mid);
    subarray right = maximun_subarray(array, mid + 1, high);
    subarray crossing = maximun_crossing_subarray(array, low, mid, high);

    if (left.sum >= right.sum && left.sum >= crossing.sum) {
        return left;
    } else if (right.sum >= left.sum && right.sum >= crossing.sum) {
        return right;
    } else {
        return crossing;
    }
}
