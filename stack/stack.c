#include <stdlib.h>
#include <string.h>

#include "stack.h"

struct stack_node {
    void *value;
    struct stack_node *parent;
};

void push(stack *s, const void *value) {
    struct stack_node *node = malloc(sizeof(struct stack_node));
    node->value = malloc(s->value_size);
    memcpy(node->value, value, s->value_size);
    node->parent = s->node;
    s->node = node;
}

void pop(stack *s, void *out) {
    struct stack_node *node = s->node;

    if (out != NULL) memcpy(out, node->value, s->value_size);
    s->node = node->parent;

    free(node->value);
    free(node);
}

void peek(const stack *s, void *out) {
    struct stack_node *node = s->node;

    memcpy(out, node->value, s->value_size);
}

int size(const stack *s) {
    int counter = 0;
    struct stack_node *node = s->node;

    while (node != NULL) {
        node = node->parent;
        counter++;
    }

    return counter;
}

stack *stack_init(size_t value_size) {
    stack *s = malloc(sizeof(stack));

    s->value_size = value_size;
    s->node = NULL;

    s->push = &push;
    s->pop = &pop;
    s->peek = &peek;
    s->size = &size;

    return s;
}

void stack_free(stack *s) {
    struct stack_node *node = s->node;

    while (node != NULL) {
        struct stack_node *parent = node->parent;

        free(node->value);
        free(node);

        node = parent;
    }

    free(s);
}
