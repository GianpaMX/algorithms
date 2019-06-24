#include <print_array.h>
#include <stdio.h>
#include "heap.h"

int intcmp(const void *a, const void *b);

int main() {
    Heap *heap = new_heap(3, sizeof(int), intcmp);

    for (int i = 40; i > 0; i -= 10) {
        heap->push(heap, &i);
    }

    print_array(heap->array, heap->max_size);

    heap->pop(heap);
    heap->pop(heap);
    heap->pop(heap);
    heap->pop(heap);

    print_array(heap->array, heap->max_size);

    free_heap(heap);
    return 0;
}

int intcmp(const void *a, const void *b) {
    return *(int *) b - *(int *) a;
}
