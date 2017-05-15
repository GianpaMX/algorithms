#ifndef ALGORITHMS_MAXIMUN_SUBARRAY_H
#define ALGORITHMS_MAXIMUN_SUBARRAY_H

typedef struct {
    int low;
    int high;
    int sum;
} subarray;

subarray maximun_crossing_subarray(const int *array, int low, int mid, int high);

subarray maximun_subarray(const int *array, int low, int high);


#endif //ALGORITHMS_MAXIMUN_SUBARRAY_H
