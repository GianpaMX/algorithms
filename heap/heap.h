#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <stdlib.h>

typedef struct Heap Heap;

struct Heap {
    int *array;
    int size;
    size_t max_size;

    int (*peek)(const Heap *heap);

    void (*push)(Heap *heap, int n);

    int (*pop)(Heap *heap);
};

Heap *new_heap(int height);

void free_heap(Heap *heap);

#endif //ALGORITHMS_HEAP_H
