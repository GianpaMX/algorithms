#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <stdlib.h>

typedef struct Heap Heap;

typedef int (*heap_cmp)(const int *a, const int *b);

struct Heap {
    int *array;
    int size;
    size_t max_size;

    int (*peek)(const Heap *heap);

    void (*push)(Heap *heap, int n);

    int (*pop)(Heap *heap);

    heap_cmp cmp;
};

Heap *new_heap(int height, heap_cmp heap_cmp);

void free_heap(Heap *heap);

#endif //ALGORITHMS_HEAP_H
