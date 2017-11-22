#include "non_zero.h"

/*
 * You are given an array of integers. Write an algorithm that brings all nonzero elements
 * to the left of the array, and returns the number of nonzero elements. The algorithm
 * should operate in place, i.e. shouldn't create a new array. The order of the nonzero
 * elements does not matter. The numbers that remain in the right portion of the array
 * can be anything. Example: given the array [ 1, 0, 2, 0, 0, 3, 4 ], a possible answer
 * is [ 4, 1, 3, 2, ?, ?, ? ], 4 non-zero elements, where "?" can be any number.
 * Code should have good complexity and minimize the number of writes to the array.
*/
int non_zero(int *array, int array_size) {
    int *zeros = 0;
    int zero_size = 0;
    int non_zero_counter = array_size;
    int i = 0;

    while(i < array_size) {
        if(array[i] == 0) {
            if(zeros == 0) {
                zeros = array + i;
            }
            zero_size = array + i - zeros + 1;
            non_zero_counter--;
        } else if(zeros) {
            *zeros = array[i];
            if(zero_size == 1) {
                zeros = array + i;
            } else {
                zeros++;
            }
        }
        i++;
    }

    return non_zero_counter;
}
