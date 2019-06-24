#include <stdlib.h>
#include <math.h>
#include <swap.h>
#include "heap.h"

int heap_peek(const Heap *heap);

void heap_push(Heap *heap, int n);

void heap_sift_up(Heap *heap, int i);

int heap_parent(int i);

int heap_pop(Heap *heap);

void heap_sift_down(Heap *heap, int i);

int heap_right_child(int i);

int heap_left_child(int i);

Heap *new_heap(int height, heap_cmp heap_cmp) {
    if (height == 0) return NULL;

    Heap *heap = malloc(sizeof(Heap));
    heap->max_size = (size_t) (pow(2, height) - 1);
    heap->array = calloc(sizeof(int), heap->max_size);

    heap->peek = &heap_peek;
    heap->push = &heap_push;
    heap->pop = &heap_pop;

    heap->cmp = heap_cmp;
}

void free_heap(Heap *heap) {
    if (heap == NULL) return;

    free(heap->array);
    free(heap);
}

int heap_peek(const Heap *heap) {
    return heap->array[0];
}

void heap_push(Heap *heap, int n) {
    heap->array[heap->size] = n;
    heap_sift_up(heap, heap->size++);
}

int heap_pop(Heap *heap) {
    heap->size--;
    swap(heap->array, heap->array + heap->size);
    heap_sift_down(heap, 0);
    return heap->array[heap->size];
}

void heap_sift_up(Heap *heap, int i) {
    if (i == 0) return;

    int parent = heap_parent(i);
    if (heap->cmp(heap->array + parent, heap->array + i) > 0) {
        swap(heap->array + parent, heap->array + i);
        heap_sift_up(heap, parent);
    }
}

void heap_sift_down(Heap *heap, int i) {
    int left_child = heap_left_child(i);
    int right_child = heap_right_child(i);

    if (left_child >= heap->size || right_child >= heap->size) return;

    if (heap->cmp(heap->array + left_child, heap->array + right_child) < 0) {
        if (heap->cmp(heap->array + i, heap->array + left_child) > 0) {
            swap(heap->array + i, heap->array + left_child);
            heap_sift_down(heap, left_child);
        }
    } else {
        if (heap->cmp(heap->array + i, heap->array + right_child) > 0) {
            swap(heap->array + i, heap->array + right_child);
            heap_sift_down(heap, right_child);
        }
    }
}

int heap_left_child(int i) {
    return 2 * i + 1;
}

int heap_right_child(int i) {
    return 2 * i + 2;
}

int heap_parent(int i) {
    return (int) floor((i - 1) / 2);
}
