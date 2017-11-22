#include "print_array.h"
#include "insertion_sort.h"


static const int SIZE = 6;

int main() {
    int array[] = {5, 2, 4, 6, 1, 3};

    print_array(array, SIZE);

    insertion_sort(array, SIZE);

    print_array(array, SIZE);

    return 0;
}
