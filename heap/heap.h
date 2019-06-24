#ifndef ALGORITHMS_HEAP_H
#define ALGORITHMS_HEAP_H

#include <stdlib.h>

typedef struct Heap Heap;

typedef int (*heap_cmp)(const void *a, const void *b);

struct Heap {
    size_t t;
    void *array;
    int size;
    size_t max_size;

    const void *(*peek)(const Heap *heap);

    void (*push)(Heap *heap, const void *n);

    const void *(*pop)(Heap *heap);

    heap_cmp cmp;
};

Heap *new_heap(int height, size_t t, heap_cmp heap_cmp);

void free_heap(Heap *heap);

#endif //ALGORITHMS_HEAP_H
