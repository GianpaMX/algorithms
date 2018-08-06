
#include "rotate_image.h"


int main() {

    int size = 5;
    arr_arr_integer a = alloc_image(size);


    int c = 1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            a.arr[i].arr[j] = c++;
        }
    }

    print_image(a);
    a = rotate_image(a);
    print_image(a);

    free_image(a);

    return 0;
}
