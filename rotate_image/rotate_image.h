#ifndef ALGORITHMS_ROTATE_IMAGE_H
#define ALGORITHMS_ROTATE_IMAGE_H

typedef struct {
    int size;
    int *arr;
} arr_integer;

typedef struct {
    int size;
    arr_integer *arr;
} arr_arr_integer;

arr_arr_integer alloc_image(int n);
arr_arr_integer free_image(arr_arr_integer a);

arr_arr_integer rotate_image(arr_arr_integer a);

void print_image(arr_arr_integer a);


#endif //ALGORITHMS_ROTATE_IMAGE_H
