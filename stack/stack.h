#ifndef ALGORITHMS_STACK_H
#define ALGORITHMS_STACK_H

#include <stddef.h>

struct stack_node;

typedef struct stack stack;

struct stack {
    struct stack_node *node;

    size_t value_size;

    void (*push)(stack *s, const void *value);

    void (*pop)(stack *s, void *out);

    void (*peek)(const stack *s, void *out);

    int (*size)(const stack *s);
};

stack *stack_init(size_t size);

void stack_free(stack *s);


#endif //ALGORITHMS_STACK_H
