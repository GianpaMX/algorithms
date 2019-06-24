#include <stdlib.h>
#include <math.h>
#include <swap.h>
#include <memory.h>
#include "heap.h"

const void *heap_peek(const Heap *heap);

void heap_push(Heap *heap, const void *n);

void heap_sift_up(Heap *heap, int i);

int heap_parent(int i);

const void *heap_pop(Heap *heap);

void heap_sift_down(Heap *heap, int i);

int heap_right_child(int i);

int heap_left_child(int i);

Heap *new_heap(int height, size_t t, heap_cmp heap_cmp) {
    if (height == 0) return NULL;

    Heap *heap = malloc(sizeof(Heap));
    heap->max_size = (size_t) (pow(2, height) - 1);
    heap->array = calloc(heap->max_size, t);
    heap->t = t;

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

const void *heap_peek(const Heap *heap) {
    return heap->array;
}

void heap_push(Heap *heap, const void *n) {
    memcpy(heap->array + heap->size * heap->t, n, heap->t);
    heap_sift_up(heap, heap->size++);
}

const void *heap_pop(Heap *heap) {
    heap->size--;
    swap(heap->array, heap->array + heap->size * heap->t, heap->t);
    heap_sift_down(heap, 0);
    return heap->array + heap->size * heap->t;
}

void heap_sift_up(Heap *heap, int i) {
    if (i == 0) return;

    int parent = heap_parent(i);
    if (heap->cmp(heap->array + parent * heap->t, heap->array + i * heap->t) > 0) {
        swap(heap->array + parent * heap->t, heap->array + i * heap->t, heap->t);
        heap_sift_up(heap, parent);
    }
}

void heap_sift_down(Heap *heap, int i) {
    int left_child = heap_left_child(i);
    int right_child = heap_right_child(i);

    if (left_child >= heap->size || right_child >= heap->size) return;

    if (heap->cmp(heap->array + left_child * heap->t, heap->array + right_child * heap->t) < 0) {
        if (heap->cmp(heap->array + i * heap->t, heap->array + left_child * heap->t) > 0) {
            swap(heap->array + i * heap->t, heap->array + left_child * heap->t, heap->t);
            heap_sift_down(heap, left_child);
        }
    } else {
        if (heap->cmp(heap->array + i * heap->t, heap->array + right_child * heap->t) > 0) {
            swap(heap->array + i * heap->t, heap->array + right_child * heap->t, heap->t);
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
