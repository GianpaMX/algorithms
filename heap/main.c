#include <print_array.h>
#include <stdio.h>
#include "heap.h"

int main() {
    Heap *heap = new_heap(3);

    heap->push(heap, 40);
    heap->push(heap, 30);
    heap->push(heap, 20);
    heap->push(heap, 10);

    print_array(heap->array, heap->max_size);

    heap->pop(heap);
    heap->pop(heap);
    heap->pop(heap);
    heap->pop(heap);

    print_array(heap->array, heap->max_size);

    free_heap(heap);
    return 0;
}
