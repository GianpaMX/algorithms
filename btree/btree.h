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

void btree_put(btree *t, const void *value);

bool btree_contains(const btree *t, void *value);

const struct btree_node *btree_find(const struct btree_node *node, void *value, int (*hash)(const void *));

void btree_insert(struct btree_node *node, int hash);

struct btree_node *btree_node_init(int hash);

void btree_node_free(struct btree_node *node);


#endif //ALGORITHMS_BTREE_H
