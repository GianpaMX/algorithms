#include <glob.h>
#include <stdlib.h>
#include <memory.h>
#include "swap.h"

void swap(void *a, void *b, size_t size) {
    void *t = malloc(size);
    memcpy(t, a, size);
    memcpy(a, b, size);
    memcpy(b, t, size);
    free(t);
}
