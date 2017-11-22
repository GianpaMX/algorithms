#include "linear_search.h"

int linear_search(int v, const int *a, int size) {
    for (int i = 0; i < size; i++) {
        if (v == a[i]) return i;
    }
    return -1;
}
