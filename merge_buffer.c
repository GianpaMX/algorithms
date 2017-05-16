#include "merge_buffer.h"

void slice_array_to_right_by_one(int *array, int size);

void merge_buffer(int *p, int data_size, int *s, int s_size) {
    int *unmerged_data = p;
    int unmerged_size = data_size;
    int s_counter = 0;

    while (unmerged_size > 0) {
        if (s_counter < s_size && *s < *unmerged_data) {
            slice_array_to_right_by_one(unmerged_data, unmerged_size);
            *unmerged_data = *s;
            s++;
            s_counter++;
        } else {
            unmerged_size--;
        }
        unmerged_data++;
    }

    while (s_counter < s_size) {
        *unmerged_data = *s;
        unmerged_data++;
        s++;
        s_counter++;
    }
}

void slice_array_to_right_by_one(int *array, int size) {
    for (int i = size; i > 0; i--) {
        array[i] = array[i - 1];
    }
}
