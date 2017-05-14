#include "insertion_sort.h"

void insertion_sort(int *a, int a_size) {
    for (int j = 1; j < a_size; j++) {
        int key = a[j];
        int i = j - 1;

        while (i > -1 && a[i] > key) {
            a[i + 1] = a[i];
            i = i - 1;
        }

        a[i + 1] = key;
    }
}
