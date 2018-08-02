#ifndef ALGORITHMS_BTREE_H
#define ALGORITHMS_BTREE_H\


#include <stdbool.h>

struct btree_node;

typedef struct btree btree;

struct btree {
    struct btree_node *node;

    int (*hash)(const void *);

    void (*put)(btree *t, const void *value);

    bool (*contains)(const btree *t, void *value);
};

btree *btree_init(int (*hash)(const void *));

void btree_free(btree *t);


#endif //ALGORITHMS_BTREE_H
